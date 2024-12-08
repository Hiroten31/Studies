package org.example;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ShapeTest {
    @Test
    void testShapePrint() {
        Color color = new Color(0, 0, 255, 100);
        Shape shape = new Rectangle(5.0, 10.0, color);
        shape.printShape();
    }

    @Test
    void testShapeColorDescription() {
        Color color = new Color(0, 0, 255, 50);
        Shape shape = new Rectangle(5.0, 10.0, color);
        shape.getColorDescription();
    }
}