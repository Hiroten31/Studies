package org.example;

import jakarta.persistence.*;

@Entity
public abstract class Shape {

    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    protected Long id;
    String nazwa;
    @Transient
    Color shapeColor;
    public abstract double getArea();
    public abstract double getPerimeter();

    public Shape(){

    }
    public Shape(Color shapeColor) {
        this.shapeColor = shapeColor;
    }

    void printShape() {
        System.out.println(this.getClass().getSimpleName() + ", pole: " + this.getArea());
    }

    void getColorDescription() {
        System.out.println("Red: " + shapeColor.R() + ", Green: " + shapeColor.G() + ", Blue: " + shapeColor.B() + ", Alpha: " + shapeColor.A());
    }
}
