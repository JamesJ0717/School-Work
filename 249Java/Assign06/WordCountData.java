public class WordCountData {
    private int charCnt;
    private int wordCnt;
    private int lineCnt;

    public WordCountData(int charCnt, int wordCnt, int lineCnt) {
        this.charCnt = charCnt;
        this.wordCnt = wordCnt;
        this.lineCnt = lineCnt;
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
