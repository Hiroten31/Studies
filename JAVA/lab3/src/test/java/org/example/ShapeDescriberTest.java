package org.example;

import org.junit.Test;
import static org.junit.Assert.*;

public class ShapeDescriberTest {
    @Test
    public void describeWithNullShape() {
        assertThrows(IllegalArgumentException.class, () -> ShapeDescriber.describe(null));
    }
    @Test
    public void describeWithNonShapeObject() {
        Object nonShapeObject = new Object();
        assertThrows(ClassCastException.class, () -> ShapeDescriber.describe((Shape) nonShapeObject));
    }
}