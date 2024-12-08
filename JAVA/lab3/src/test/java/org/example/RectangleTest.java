package org.example;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RectangleTest {
    @Test
    void testRectangleArea() {
        Color color = new Color(255, 0, 0, 100); // Red color
        Rectangle rectangle = new Rectangle(5.0, 10.0, color);
        assertEquals(50.0, rectangle.getArea(), "Area should be width * height");
    }

    @Test
    void testRectanglePerimeter() {
        Color color = new Color(255, 0, 0, 100); // Red color
        Rectangle rectangle = new Rectangle(5.0, 10.0, color);
        assertEquals(30.0, rectangle.getPerimeter(), "Perimeter should be 2 * (width + height)");
    }

    @Test
    void testRectangleColor() {
        Color color = new Color(255, 0, 0, 100); // Red color
        Rectangle rectangle = new Rectangle(5.0, 10.0, color);
        assertEquals(color, rectangle.shapeColor, "Rectangle color should match the given color");
    }
}