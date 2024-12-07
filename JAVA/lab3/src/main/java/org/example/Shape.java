package org.example;

public abstract class Shape {
    String nazwa;
    Color shapeColor;
    public abstract double getArea();
    public abstract double getPerimeter();

    public Shape(Color shapeColor) {
        this.shapeColor = shapeColor;
    }

    void printShape() {
        System.out.println(this.getClass().getSimpleName());
    }

    void getColorDescription() {
        System.out.println("Red: " + shapeColor.R() + ", Green: " + shapeColor.G() + ", Blue: " + shapeColor.B() + ", Alpha: " + shapeColor.A());
    }
}
