package org.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

public class ShapeDescriberTest {
    @Test
    void testDescribeWithValidShape() {
        ByteArrayOutputStream outContent = new ByteArrayOutputStream();
        System.setOut(new PrintStream(outContent));

        Color red = new Color(255, 0, 0, 100);
        Shape rectangle = new Rectangle(5.0, 10.0, red);

        ShapeDescriber.describe(rectangle);

        String output = outContent.toString();

        assertTrue(output.contains("Type = Rectangle"), "Output should contain shape type");
        assertTrue(output.contains("Color = Color[R=255, G=0, B=0, A=100]"), "Output should contain shape color");
        assertTrue(output.contains("Area = 50.0"), "Output should contain shape area");
        assertTrue(output.contains("Perimeter = 30.0"), "Output should contain shape perimeter");
    }

    @Test
    void testDescribeWithNullShape() {
        IllegalArgumentException exception = assertThrows(IllegalArgumentException.class, () -> {
            ShapeDescriber.describe(null);
        });

        assertEquals("You must give a shape object.", exception.getMessage(), "Exception message should match");
    }
}