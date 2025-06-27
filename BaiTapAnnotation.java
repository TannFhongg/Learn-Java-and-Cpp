import java.lang.annotation.Target;
import java.lang.reflect.Method;
import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

@Target(ElementType.METHOD)
@Retention(RetentionPolicy.RUNTIME)
@interface Info {
    String author() default "Tuan";

    int version() default 1;
}

class ThayDoi {
    @Info(author = "Tuan", version = 2)
    public void display() {
        System.out.println("Hello World");
    }
}   

public class BaiTapAnnotation {
    public static void main(String[] args) {
        try {
            ThayDoi thayDoi = new ThayDoi();
            Method method = thayDoi.getClass().getMethod("display");
            Info info = method.getAnnotation(Info.class);
            System.out.println(info.author());
            System.out.println(info.version());
        } catch (NoSuchMethodException e) {
            System.out.println("Method not found");
        }
    }
}
