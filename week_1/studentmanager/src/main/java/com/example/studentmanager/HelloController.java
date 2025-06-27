package com.example.studentmanager;

import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api") 

class HelloController {
    @GetMapping("/hello")
    public String sayHello() {
        return "Xin chao tu Spring Boot!";
    }
    @GetMapping("/hello/{name}")
    public String sayHello(@PathVariable String name) {
        return "Xin chao, " + name + "!";
    }

}