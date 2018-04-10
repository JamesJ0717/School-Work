import java.lang.Exception;

public class InvalidExpressionException extends Exception {

    public InvalidExpressionException(String message, Exception e) {
            super(message, e);
    }
    private static final long serialVersionUID = 1L;
}
