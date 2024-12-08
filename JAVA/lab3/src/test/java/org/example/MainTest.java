package org.example;

import org.junit.jupiter.api.Test;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

import static org.junit.jupiter.api.Assertions.*;

class MainTest {
    @Test
    void testMainExecution() {
        ByteArrayOutputStream outContent = new ByteArrayOutputStream();
        System.setOut(new PrintStream(outContent));

        Main.main(null);

        String output = outContent.toString();

        assertTrue(output.contains("Type = Triangle"), "Output should contain triangle type");
        assertTrue(output.contains("Color = Color[R=0, G=255, B=0, A=100]"), "Output should contain triangle color");
        assertTrue(output.contains("Area = 12.0"), "Output should contain triangle area");
        assertTrue(output.contains("Perimeter = 12.0"), "Output should contain triangle perimeter");

        assertTrue(output.contains("Type = Rectangle"), "Output should contain rectangle type");
        assertTrue(output.contains("Color = Color[R=255, G=255, B=255, A=0]"), "Output should contain rectangle color");
        assertTrue(output.contains("Area = 12.0"), "Output should contain rectangle area");
        assertTrue(output.contains("Perimeter = 14.0"), "Output should contain rectangle perimeter");
    }
}