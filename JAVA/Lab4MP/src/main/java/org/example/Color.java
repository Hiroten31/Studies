package org.example;

public record Color(int R, int G, int B, int A) {
    public Color(int R, int G, int B, int A) {
        if(R < 0 || R > 255 || G < 0 || G > 255 || B < 0 || B > 255 || A < 0 || A > 100) {
            throw new IllegalArgumentException("Provide correct color (0-255) and alpha (0-100) values.");
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
