1. Błąd jaki mi przeszkodził


![1blad](https://github.com/user-attachments/assets/25139e14-9215-4586-ada9-ed8aa4274627)


2. MainApplication pod SpringBoot.


![1MainApp](https://github.com/user-attachments/assets/2bcb6e33-0cc9-49c0-9634-5c38857dc8e8)


3. Włączona aplikacja + błąd po przesłaniu requestu od Postmana.
Błąd: Cannot construct instance of `org.example.Shape` (no Creators, like default constructor, exist): abstract types either need to be mapped to concrete types, have custom deserializer, or contain addition type information (...)


![1MainAppRunError](https://github.com/user-attachments/assets/25181028-b5d0-41d3-87fd-d1a1e6254142)


4. Klasa Rectangle (dodanie @Table(name="rectangles") też powodawało błędy)


![2Rectangle](https://github.com/user-attachments/assets/ba0d9cb3-1954-46d3-8f2d-a4b45d02807d)


5. Klasa Shape, z @Transient, aby zobaczyć czy przejdzie zapytanie - próbowałem także ustawić zapytanie bez "color": {r,g,b,a}. 


![3Shape](https://github.com/user-attachments/assets/8998b75b-83d1-4f5b-8bcc-e2ef6627b21b)


6. Rekord Color bez zmian od labów 3.


![4Color](https://github.com/user-attachments/assets/b3687e44-e9e2-4975-852f-17317b014671)


7. Otrzymany request na POST i GET.


![5PostmanError](https://github.com/user-attachments/assets/182939ed-6910-4384-bd38-1dc1281a0e65)


8. Wygląd bazy od strony terminala. Tabela zrobiona przez SpringBoota.


![6DB](https://github.com/user-attachments/assets/4b673b07-f1a4-4adc-9261-1b63c6fe95be)


