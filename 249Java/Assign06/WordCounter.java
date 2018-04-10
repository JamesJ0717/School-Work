import java.util.Scanner;
import java.net.URL;

public class WordCounter{
    public static WordCountData count(String path) throws Exception{
        if(path.contains("http")){
            try {
                Scanner pageInput = new Scanner(url.openStream());

                int wordCnt = 0;
                int lineCnt = 0;
                int charCnt = 0;

                while(pageInput.hasNext()){
                    if (pageInput.next() == " ") {
                        wordCnt++;
                    }
                    else if (pageInput.hasNext("\n")) {
                        lineCnt++;
                    }
                }
            }


        }
        return ();
    }
}
