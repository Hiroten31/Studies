package org.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;


public class ColorTest {

  @Test
  public void testValidColorValues() {
    new Color(0, 0, 0, 0);
    new Color(255, 255, 255, 100);
  }

  @Test
  public void testInvalidColorValues() {
    assertThrows(IllegalArgumentException.class, () -> new Color(-1, 0, 0, 0)); // R < 0
    assertThrows(IllegalArgumentException.class, () -> new Color(256, 0, 0, 0)); // R > 255
    assertThrows(IllegalArgumentException.class, () -> new Color(0, -1, 0, 0)); // G < 0
    assertThrows(IllegalArgumentException.class, () -> new Color(0, 256, 0, 0)); // G > 255
    assertThrows(IllegalArgumentException.class, () -> new Color(0, 0, -1, 0)); // B < 0
    assertThrows(IllegalArgumentException.class, () -> new Color(0, 0, 256, 0)); // B > 255
    assertThrows(IllegalArgumentException.class, () -> new Color(0, 0, 0, -1)); // A < 0
    assertThrows(IllegalArgumentException.class, () -> new Color(0, 0, 0, 101)); // A > 100
  }

  @Test
  public void testValidColorThreeArguments() {
    Color color = new Color(100, 150, 200); // Alpha powinno być domyślnie 0
    assertEquals(100, color.R());
    assertEquals(150, color.G());
    assertEquals(200, color.B());
    assertEquals(0, color.A());
  }

  @Test
  public void testBoundaryValuesAssignment() {
    Color color = new Color(255, 255, 255, 100);
    assertEquals(255, color.R());
    assertEquals(255, color.G());
    assertEquals(255, color.B());
    assertEquals(100, color.A());
  }
}