package com.dev.tula;

import com.fasterxml.jackson.databind.ObjectMapper;
import org.springframework.beans.factory.annotation.Autowired;




public class Boy {
    @Autowired
    private ObjectMapper objectMapper;

    
    public void userObjectMapper() {
        System.out.println("objectMapper: " + objectMapper);
    }

}