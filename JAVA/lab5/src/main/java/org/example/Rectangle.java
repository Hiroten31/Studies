package org.example;
import jakarta.persistence.*;

@Entity
public class Rectangle extends Shape {
    double width;
    double height;

    public Rectangle() {}
    public Rectangle(double width, double height, Color color) {
        super(color);
        this.width = width;
        this.height = height;
    }
    @Override
    public double getArea() {
        return width * height;
    }

    @Override
    public double getPerimeter() {
        return 2 * width + 2 * height;
    }

}
