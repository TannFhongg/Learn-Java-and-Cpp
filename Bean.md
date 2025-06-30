Bean 

Những obj được tạo và quản lí bởi Spring IoC Container được gọi là Bean. 
---------------------------------------------------------------------------
Cách tạo bean 
1. Dùng @Component : @Repository @Service,@Controller

2. Dùng @Bean trong class có annotation @Configuration 
-------------------------------------------------------------------------------------------
@Configuration : 
là 1 annotation đánh dấu trên 1 class,cho biết rằng class đó chứa các thông tin cấu hình cho ứng dụng 

Spring Boot sẽ tìm và quét các class được đánh dấu @Configuration để tạo và quản lí các bean  
-------------------------------------------------------------------------------------------
@Bean 
là 1 annotation đánh dấu trên 1 method trong class được đánh dấu @Configuration.Nó cho biết rằng method đó tạo và trả về bằng bean, và Spring boot nên quản lí bean đó trong ứng dụng.

-----------------------------------------------------------------------------------------

Bean scope 
1. Singleton : container chỉ khởi tạo 1 instance của bean và trả về chính nó nếu như có yêu cầu 
2. Prototype: mỗi khi có yêu cầu thì container sẽ tạo ra 1 instance mới và trả về
3. Request: Khởi tạo instance cho 1 http request
4. Session : Khởi tạo instance cho 1 http session 
5. Application : khởi tạo instance cho 1 vòng đời của ServletContext
6. WebSocket: khởi tạo instance cho 1 web socket session