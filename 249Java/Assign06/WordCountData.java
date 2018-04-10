public class WordCountData {
    private int charCnt;
    private int wordCnt;
    private int lineCnt;

    public WordCountData(int numChars, int numWords, int numLines) {
        this.charCnt = numChars;
        this.wordCnt = numWords;
        this.lineCnt = numLines;
    }

    public int getCharCnt() {
        return charCnt;
    }

    public int getWordCnt() {
        return wordCnt;
    }

    public int getLineCnt() {
        return lineCnt;
    }
}
