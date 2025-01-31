package org.example;


import java.util.List;
import java.util.Scanner;

public class Main {

    private static final Scanner scanner = new Scanner(System.in);
    private static final ShapeDAO shapeDAO = new ShapeDAO();

    public static void main(String[] args) {
        boolean petla = false;
        while(!petla) {
            switch(printMenu()) {
                case 1 -> create();
                case 2 -> readAll();
                case 3 -> read();
                case 4 -> update();
                case 5 -> delete();
                case 6 -> {
                    petla = true;
                }
            }
        }
        scanner.close();

    }

    private static int printMenu() {
        System.out.println("Wybierz opcje:");
        System.out.println("1. Stworz rekord");
        System.out.println("2. Odczytaj wszystkie rekordy");
        System.out.println("3. Odczytaj rekord");
        System.out.println("4. Zaktualizuj");
        System.out.println("5. Usun");
        System.out.println("6. Wyjdz");
        System.out.print("Co zrobic?\n");

        while (!scanner.hasNextInt()) {
            System.out.print("Zly input, podaj liczbe: ");
            scanner.next();
        }
        return scanner.nextInt();
    }
    private static int getChoice() {
        while (!scanner.hasNextInt()) {
            System.out.print("Invalid input. Please enter a number: ");
            scanner.next();
        }
        return scanner.nextInt();
    }

    private static void create() {

        System.out.print("If You want to create Rectangle enter 1, if You want to create Triangle enter 2: ");
        int choice = getChoice();

        if (choice == 1) {
            Rectangle rectangle = ShapeFactory.rectangleCreator(scanner);
            shapeDAO.save(rectangle);
        } else if (choice == 2) {
            Triangle triangle = ShapeFactory.triangleCreator(scanner);
            shapeDAO.save(triangle);
        } else {
            System.out.println("Invalid input");
        }

    }

    private static void readAll() {
        List<Shape> shapes = shapeDAO.getAllShapes();
        for (var item : shapes) {
            System.out.println(item );
        }
    }

    private static void read() {
        System.out.print("Enter ID of shape that You want to display: ");
        long id = getChoice();
        Shape shape = shapeDAO.getById(id);
        System.out.println(shape);

    }

    private static void update() {
        System.out.print("Enter ID of shape that You want to update: ");
        long id = getChoice();
        shapeDAO.update(shapeDAO.getById(id));
    }

    private static void delete() {
        System.out.print("Enter ID of shape that You want to delete: ");
        long id = getChoice();
        shapeDAO.deleteById(id);
    }
}