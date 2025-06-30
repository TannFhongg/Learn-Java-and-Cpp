package com.dev.tula;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;

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

Client client = context.getBean(Client.class);
client.processMessage("Hello ,world");
    }
}
