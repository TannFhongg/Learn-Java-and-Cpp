package com.dev.tula;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component
public class Client {

    @Autowired
    MessageService messageService; 
/*  @Autowired
    Client(MessageService messageService) {
        this.messageService = messageService; 
    }
*/
    
    public void processMessage(String message) {
        messageService.sendMessage(message);
    }

}
