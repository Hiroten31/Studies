package org.example;

public class Triangle extends Shape {
    double sideA, sideB, sideC, height;
    public Triangle(double sideA, double sideB, double sideC, double height, Color color) {
        super(color);
        this.sideA = sideA;
        this.sideB = sideB;
        this.sideC = sideC;
        this.height = height;
    }
    public double getArea() {
        return sideB * (0.5*height);
    }
    public double getPerimeter() {
        return sideA+sideB+sideC;
    }
}
