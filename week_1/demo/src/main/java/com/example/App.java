package com.example;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class App {
    public static void main(String[] args) {
        SpringApplication.run(App.class, args);
    }
}

/*
Annotation này là trái tim của Spring Boot, nó là tổ hợp của 3 annotation quan trọng:
 * @SpringBootApplication = @Configuration + @EnableAutoConfiguration + @ComponentScan

@ComponentScan: tự động quét các class cùng package hoặc package con để tìm các component như:

@Controller, @RestController

@Service

@Repository
@Component
 */