package com.dev.tula;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;
import com.fasterxml.jackson.databind.ObjectMapper;
/**
 * Hello world!
 *
 */
@SpringBootApplication
public class App 
{
    public static void main( String[] args )
    {
ApplicationContext context = SpringApplication.run(App.class, args);
Boy boy = context.getBean(Boy.class);
boy.userObjectMapper();



    }
}
