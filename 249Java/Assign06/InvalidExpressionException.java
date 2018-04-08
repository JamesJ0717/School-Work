public class InvalidExpressionException extends Exception {
  InvalidExpressionException(String message, Exception e) {
    super(message, e);
  }
}
