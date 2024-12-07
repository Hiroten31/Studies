# Laboratorium 3 - Java, gr. lab. 3, Piech Mikołaj.

## Zadania
### Zadanie 1: Przygotowanie projektu Maven
![image](https://github.com/user-attachments/assets/a0c89ae0-96fb-4550-a056-f558258ff830)
```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <modelVersion>4.0.0</modelVersion>

    <groupId>org.example</groupId>
    <artifactId>LAB2</artifactId>
    <version>1.0-SNAPSHOT</version>

    <properties>
        <maven.compiler.source>23</maven.compiler.source>
        <maven.compiler.target>23</maven.compiler.target>
        <project.build.sourceEncoding>UTF-8</project.build.sourceEncoding>
    </properties>

</project>
```

### Zadanie 2: Rozszerzenie klasy Shape o kolor

1. Dodaj pole Color do klasy Shape, aby każda figura mogła mieć przypisany kolor.
```java
public abstract class Shape {
    String nazwa;
    Color shapeColor;
    public abstract double getArea();
    public abstract double getPerimeter();

    void printShape() {
        System.out.println(this.getClass().getSimpleName());
    }
}
```  
2. Zaktualizuj konstruktor klasy Shape, aby przyjmował obiekt typu Color.
```java
public Shape(Color shapeColor) {
    this.shapeColor = shapeColor;
}
```
oraz dodanie super() do klas dziedziczących:
Triangle.java
```java
public Triangle(double sideA, double sideB, double sideC, double height, Color color) {
        super(color);
        this.sideA = sideA;
        this.sideB = sideB;
        this.sideC = sideC;
        this.height = height;
    }
```
Rectangle.java
```java
public Rectangle(double width, double height, Color color) {
        super(color);
        this.width = width;
        this.height = height;
    }
```
3. Dodaj metodę getColorDescription, która zwraca tekstowy opis koloru figury (np. "Red: 255, Green: 0, Blue: 0, Alpha: 255").
```java
void getColorDescription() {
    System.out.println("Red: " + shapeColor.R() + ", Green: " + shapeColor.G() + ", Blue: " + shapeColor.B() + ", Alpha: " + shapeColor.A());
}
```
4. Zaktualizuj funkcję main, aby tworzyć obiekty figur z przypisanymi kolorami.
```java
public class Main {
    public static void main(String[] args) {
        Color zielony = new Color(0, 255, 0, 100);
        Color bialy = new Color(255, 255, 255);

        Shape zielonyTrojkat = new Triangle(3, 4, 5, 6, zielony);
        Shape bialyProstokat = new Rectangle(3, 4, bialy);

        zielonyTrojkat.getColorDescription();
        bialyProstokat.getColorDescription();
    }
}
```
Wynik uruchomienia:

![image](https://github.com/user-attachments/assets/fb319763-b498-476e-900e-1370b5a029cb)


### Zadanie 3: Logowanie informacji z wykorzystaniem SLF4J
1. Dodaj zależność do biblioteki SLF4J w pliku pom.xml:
```xml
<dependencies>
        <dependency>
            <groupId>org.slf4j</groupId>
            <artifactId>slf4j-api</artifactId>
            <version>2.0.7</version>
         </dependency>
</dependencies>
```
IntellIJ IDEA ma problem ze znaleziem wersji 'slf4j-api', tym samym importowania bibliotek. Rozwiązanie to usunięcie folderu '.idea' i otworzenie projektu z pliku pom.xml


2. Zaimplementuj logowanie w klasie ShapeDescriber:
```java
package org.example;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class ShapeDescriber {
    static final Logger logger = LoggerFactory.getLogger(ShapeDescriber.class);

    public static void describe(Shape shape) {
        logger.info("Type = {} ", shape.getClass().getSimpleName());
        logger.info("Color = {} ", shape.shapeColor);
        logger.info("Area = {}", shape.getArea());
        logger.info("Perimeter = {}", shape.getPerimeter());
    }
}

```

3. Przetestuj działanie logowania w funkcji main:
```java
public class Main {
    public static void main(String[] args) {
        Color zielony = new Color(0, 255, 0, 100);
        Color bialy = new Color(255, 255, 255);

        Triangle zielonyTrojkat = new Triangle(3, 4, 5, 6, zielony);
        Rectangle bialyProstokat = new Rectangle(3, 4, bialy);

        ShapeDescriber.describe(zielonyTrojkat);
        ShapeDescriber.describe(bialyProstokat);

    }
}
```

Wynik uruchomienia (na brak informacji z loggera pomogło przeładowanie i debug projektu):
![image](https://github.com/user-attachments/assets/7d4e43c3-5456-48af-9134-349b0648e097)


### ~~Zadanie 4: Polimorfizm i rozszerzenie funkcjonalności~~


### Zadanie 5: Dodaj testy jednostkowe
Według 'Run with Coverage' projekt pokrywa 80% metod oraz 84% linii kodu.
![image](https://github.com/user-attachments/assets/7adc9e62-7fc3-4c67-b570-9bbb326a9fbb)

ColorTest.java:
```java
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
```

ShapeDescriberTest.java:
```java
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
```
