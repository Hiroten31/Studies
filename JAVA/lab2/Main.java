package org.example;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public record Color(int R, int G, int B, int A) {
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
    }

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
}