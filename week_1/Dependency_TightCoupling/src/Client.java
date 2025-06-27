public class Client implements InjectionMessageService {

    private MessageService messageService;

    // Client(MessageService messageService) { // constructor Injection
    //     this.messageService = messageService;
    // }
    /* 
    public void setMessageService(MessageService messageService) { // setter Injection
        this.messageService = messageService; 
    } */

    // interface injection 
@Override
    public void setService(MessageService nMessageService) {
        this.messageService = nMessageService; 
    }

    public void processMessage(String message) {
        messageService.sendMessage(message);
    }
}
