public class Calculator {
  public static double eval(String expr) throws InvalidExpressionException {
    double answer = 0.0;
    try {
      if (!(expr.contains("+")) && !(expr.contains("-"))) {
        Exception e = new Exception("Invalid Expression");
        throw e;
      }
      if (expr.contains("-")) {
        String firstNumberIndex = expr.substring(0, expr.indexOf("-"));
        String secondNumberIndex = expr.substring(expr.indexOf("-")+1);
        double firstNumber = Double.parseDouble(firstNumberIndex);
        double secondNumber = Double.parseDouble(secondNumberIndex);
        answer = firstNumber - secondNumber;
      }
      else if (expr.contains("+")) {
        String firstNumberIndex = expr.substring(0, expr.indexOf("+"));
        String secondNumberIndex = expr.substring(expr.indexOf("+")+1);
        double firstNumber = Double.parseDouble(firstNumberIndex);
        double secondNumber = Double.parseDouble(secondNumberIndex);
        answer = firstNumber + secondNumber;
      }
    }
    catch (Exception e)
    {
      throw new InvalidExpressionException("Invalid Expression", e);
    }
    finally
    {

    }
    return (answer);
    }

  }
