package org.example;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class ShapeDescriber {
    static final Logger logger = LoggerFactory.getLogger(ShapeDescriber.class);

    public static void describe(Shape shape) {
        if (shape == null) {
            throw new IllegalArgumentException("You must give a shape object.");
        }
        logger.info("Type = {} ", shape.getClass().getSimpleName());
        logger.info("Color = {} ", shape.shapeColor);
        logger.info("Area = {}", shape.getArea());
        logger.info("Perimeter = {}", shape.getPerimeter());
    }
}
