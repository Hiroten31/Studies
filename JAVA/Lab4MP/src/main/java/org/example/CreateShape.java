package org.example;
import java.util.Scanner;

public class CreateShape {
    public static Triangle triangleCreator(Scanner scanner) {
        System.out.print("Wprowadz bok A: ");
        double bokA = scanner.nextDouble();
        System.out.print("Wprowadz bok B: ");
        double bokB = scanner.nextDouble();
        System.out.print("Wprowadz bok C: ");
        double bokC = scanner.nextDouble();
        System.out.print("Wprowadz wysokosc: ");
        double wysokosc = scanner.nextDouble();
        System.out.print("Podaj czerwony kolor: ");
        int red = scanner.nextInt();
        System.out.print("Podaj zielony kolor: ");
        int green = scanner.nextInt();
        System.out.print("Podaj niebieski kolor: ");
        int blue = scanner.nextInt();

        Color color = new Color(red,green,blue);

        return new Triangle(bokA, bokB, bokC, wysokosc, color);

    }

    public static Rectangle rectangleCreator(Scanner scanner) {

        System.out.print("Enter desired rectangle a side: ");
        double a = scanner.nextDouble();
        System.out.print("Enter desired rectangle b side: ");
        double b = scanner.nextDouble();
        System.out.print("Enter desired color alpha parameter: ");
        int alpha = scanner.nextInt();
        System.out.print("Enter desired color red parameter: ");
        int red = scanner.nextInt();
        System.out.print("Enter desired color green parameter: ");
        int green = scanner.nextInt();
        System.out.print("Enter desired color blue parameter: ");
        int blue = scanner.nextInt();

        Color color = new Color(alpha,red,green,blue);

        return new Rectangle(color,a,b);
    }

}
