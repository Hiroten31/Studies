import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class Main {

    //Kod funkcji Hash, czyli algorytmu SHA-512 wziety z https://stackoverflow.com/questions/33085493/how-to-hash-a-password-with-sha-512-in-java
    public static String H(String input) {
        String generatedPassword = null;
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-512");
            byte[] bytes = md.digest(input.getBytes(StandardCharsets.UTF_8));
            StringBuilder sb = new StringBuilder();
            for(int i=0; i < bytes.length; i++){
                sb.append(Integer.toString((bytes[i] & 0xff) + 0x100, 16).substring(1));
            }
            generatedPassword = sb.toString();
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        return generatedPassword;
    }

    //Funkcja, ktora dopisuje do tajnego klucza zera po lewej stronie, az osiagnie 1024 bity
    public static String paddingKey(String key) {
        StringBuilder resultBuilder = new StringBuilder(key);
        while(resultBuilder.length() < 1024) {
            resultBuilder.append('0');
        }
        return resultBuilder.toString();
    }

    //Konwersja Stringa do kodu zero-jedynkowego
    public static String stringToBinary(String key) {
        byte[] bytes = key.getBytes();
        StringBuilder binary = new StringBuilder();
        for (byte b : bytes) {
            int val = b;
            for (int i = 0; i < 8; i++) {
                binary.append((val & 128) == 0 ? 0 : 1);
                val <<= 1;
            }
        }
        return binary.toString();
    }

    //Sprawdzenie czy wiadomosci przekazane do SHA-512 maja 1024 bity, jesli nie, dopisz zera
    public static String check1024(String m) {
        StringBuilder resultBuilder = new StringBuilder(m);
        while(resultBuilder.length()%1024 != 0) {
            resultBuilder.append('0');
        }
        return resultBuilder.toString();
    }

    //Funkcja ktora powtarza zawartosc ipad i opad, aby osiagnely 1024 bity
    public static String paddingIOpad(String iopad) {
        StringBuilder resultBuilder = new StringBuilder(iopad);
        while(resultBuilder.length() < 1024) {
            resultBuilder.append(iopad);
        }
        return resultBuilder.toString();
    }

    //Funkcja wykonujaca bramke logiczna XOR na argumentach
    public static String XOR(String ipad, String key) {
        StringBuilder resultBuilder = new StringBuilder();
        for(int i = 0; i < 1024; i++) {
            int res = 0;
            if(ipad.charAt(i) != key.charAt(i)) {
                res++;
            }
            resultBuilder.append(res);
        }
        return resultBuilder.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Podaj wiadomosc do zakodowania: ");
        String wiadomosc = scanner.nextLine();
        System.out.println("Podaj tajny klucz: ");
        String klucz = scanner.nextLine();

        //Nasza wiadomosc zostaje zmieniona na bity
        String M = stringToBinary(wiadomosc);
        //Uzupelnienie ostatniego bloku 1024-bitow zerami przy uzyciu funkcji
        M = check1024(M);

        //Tworzymy klucz, zmieniamy go na bity i od razu uzupelniamy go, aby posiadal 1024 bity przed dodanie zer z lewej strony
        String K = paddingKey(stringToBinary(klucz));
        System.out.println("K+  : " + K);

        //Tworzymy ipad (HEX: 36) i od razu uzupelniamy go, aby posiadal 1024 bity przez zapetlenie go
        String ipad = paddingIOpad("00110110");
        System.out.println("Ipad: " + ipad);

        //Dodajemy klucz i ipad do siebie uzywajac operacji logicznej XOR, otrzymujemy Si
        String Si = XOR(ipad, K);
        System.out.println("Si  : " + Si);

        //Pierwsze uzycie kodowania wiadomosci przez funkcje Hash.
        System.out.println("Zakodowana wiadomosc: " + H(Si + M) + "\n");

        //Ponowne kodowanie wiadomosci uzywajac poprzedniego kodu Hash i mieszajac sekretny klucz z opad
        System.out.println("K+  : " + K);

        //Tworzymy opad (HEX: 5C) i od razu uzupelniamy go, aby posiadal 1024 bity przez zapetlenie go
        String opad = paddingIOpad("01011100");
        System.out.println("Opad: " + opad);

        //Dodajemy klucz i opad do siebie uzywajac operacji logicznej XOR, otrzymujemy So
        String So = XOR(opad, K);
        System.out.println("So  : " + So);

        //Przejrzyste zapisanie funkcji tworzacej ostateczny kod HMAC
        //(wewnetrza funckja Hash jest w funkcji, dopisujacej zera, aby miec 1024 bity, zamiast 512)
        String HMAC = H(So + check1024(H(Si + M)));
        System.out.println("Ostateczny kod HMAC to: " + HMAC);
    }
}
