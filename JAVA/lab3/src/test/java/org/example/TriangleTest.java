package org.example;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class TriangleTest {
    @Test
    void testTriangleArea() {
        Color color = new Color(0, 255, 0, 100); // Green color
        Triangle triangle = new Triangle(3.0, 4.0, 5.0, 6.0, color);
        assertEquals(12.0, triangle.getArea(), "Area should be 0.5 * base * height");
    }

    @Test
    void testTrianglePerimeter() {
        Color color = new Color(0, 255, 0, 100); // Green color
        Triangle triangle = new Triangle(3.0, 4.0, 5.0, 6.0, color);
        assertEquals(12.0, triangle.getPerimeter(), "Perimeter should be sideA + sideB + sideC");
    }

    @Test
    void testTriangleColor() {
        Color color = new Color(0, 255, 0, 100); // Green color
        Triangle triangle = new Triangle(3.0, 4.0, 5.0, 6.0, color);
        assertEquals(color, triangle.shapeColor, "Triangle color should match the given color");
    }
}