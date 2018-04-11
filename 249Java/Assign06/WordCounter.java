import java.net.URL;

import java.io.File;
import java.net.URL;
import java.util.Scanner;

public class WordCounter {
    public static WordCountData count(String path) throws Exception {
        int wordCnt = 0;
        int lineCnt = 0;
        int charCnt = 0;
        if (path.contains("http")) {
            URL website = new URL(path);
            Scanner pageInput = new Scanner(website.openStream());

            while (pageInput.hasNext()) {
                String line = pageInput.nextLine();
                charCnt += line.length();
                for (int x = 0; x < line.length(); x++) {
                    if (line.charAt(x) == ' ') {
                        wordCnt++;
                    }
                }
                if (line.endsWith("\n")) {
                    wordCnt++;
                }
                lineCnt++;
            }
            pageInput.close();
            WordCountData webData = new WordCountData(charCnt, wordCnt, lineCnt);
            return (webData);
        } else {
            File data = new File(path);
            Scanner fileInput = new Scanner(data);

            while (fileInput.hasNext()) {
                String line = fileInput.nextLine();
                charCnt += line.length();
                for (int x = 0; x < line.length(); x++) {
                    if (line.charAt(x) == ' ') {
                        wordCnt++;
                    }
                }
                if (line.endsWith("\n")) {
                    wordCnt++;
                }
                lineCnt++;
            }

            fileInput.close();
            WordCountData fileData = new WordCountData(charCnt, wordCnt, lineCnt);
            return (fileData);
        }
    }
}
