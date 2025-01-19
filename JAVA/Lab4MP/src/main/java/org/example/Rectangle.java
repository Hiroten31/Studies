package org.example;

public class Rectangle extends Shape {
    double width, height;
    public Rectangle(double width, double height, Color color) {
        super(color);
        this.width = width;
        this.height = height;
    }
    public double getArea() {
        return width * height;
    }
    public double getPerimeter() {
        return 2 * width + 2 * height;
    }
}
