# Laboratorium 2 - Java, gr. lab. 3, Piech Mikołaj.

## Zadania:
### 1. Zaimplementuj klasę Color reprezentującą kolor w modelu RGB i korzystając z konceptu rekordów w Javie (słowo kluczowe record, rozwiązania tworzące klasę Color będą ocenione na 0 punktów).

```java
  public record Color(int R, int G, int B, int A) {}
```

### 2. Model RGB może być rozszerzony o kanał Alpha. Wszystkie cztery parametry powinny być obsługiwane przez konstruktor kanoniczny a dodatkowo powinna być możliwość tworzenia rekordu bez podawania wartości kanału alfa - wtedy ma on otrzymywać domyślną wartość 0.

```java
public Color(int R, int G, int B, int A) {
            if(R < 0 || R > 255 || G < 0 || G > 255 || B < 0 || B > 255 || A < 0 || A > 100) {
                throw new IllegalArgumentException("Provide correct color (0-255) and alpha (0-100) values.") {

                };
            } else {
                this.R = R;
                this.G = G;
                this.B = B;
                this.A = A;
            }
        }

        public Color(int R, int G, int B) {
            this(R, G, B, 0);
        }
```

### 3. Zademonstruj w funkcji main tworzenie obiektów typu Color, wypisywanie ich składowych oraz działanie metody toString().

```java
public static void main(String[] args) {
        Color Zielony = new Color(0, 255, 0, 100);

        Color Bialy = new Color(255, 255, 255);

        System.out.println("\n(Zielony) toString(): " + Zielony.toString());
        System.out.println("Wypisywanie skladowych: ");
        System.out.println("R: " + Zielony.R + ", G:" + Zielony.G + ", B:" + Zielony.B + ", A:" + Zielony.A);

        System.out.println("\n(Bialy) toString(): " + Bialy.toString());
        System.out.println("Wypisywanie skladowych: ");
        System.out.println("R: " + Bialy.R + ", G:" + Bialy.G + ", B:" + Bialy.B + ", A:" + Bialy.A);
    }
```

### Wynik uruchomienia metody main:

![image](https://github.com/user-attachments/assets/90ae085f-b63b-4498-b69c-9aa3bb0a0743)
