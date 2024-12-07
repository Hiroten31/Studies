package org.example;

public class Main {
    public static void main(String[] args) {
        Color zielony = new Color(0, 255, 0, 100);
        Color bialy = new Color(255, 255, 255);

        Triangle zielonyTrojkat = new Triangle(3, 4, 5, 6, zielony);
        Rectangle bialyProstokat = new Rectangle(3, 4, bialy);

        ShapeDescriber.describe(zielonyTrojkat);
        ShapeDescriber.describe(bialyProstokat);

    }
}