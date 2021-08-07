/**
 * @param {string} beginWord
 * @param {string} endWord
 * @param {string[]} wordList
 * @return {number}
 */
var ladderLength = function(beginWord, endWord, wordList) {
    var mapWords = new Map();
    var queue = new Array();
    var notFound = true;
    var count = 1;
    for (var idx = 0; idx < wordList.length; idx++) {
        if (diffWords(beginWord, wordList[idx])) {
            // one character different than beginWord
            queue.push(wordList[idx]);
        } else {
            // more than one character different from beginWord
            mapWords.set(wordList[idx], idx);
        }
        if (endWord == wordList[idx]) notFound = false;
    }
    // endWord not in the array
    if (notFound) return 0;
    while (queue.length > 0) {
        var tempQueue = queue; // use a temp queue so that we don't have to use shift().
        queue = []; // reinitialize queue for a new round of adjacent words
        count++;
        // going through the queue to look for words from map that are 1 character different
        // append it to the queue and remove it from the map
        for (var i = 0; i < tempQueue.length; i++) {
            if (tempQueue[i] == endWord) return count;
            for (const [key, value] of mapWords) {
                if (diffWords(tempQueue[i], key)) {
                    queue.push(key);
                    mapWords.delete(key);
                }
            }
        }
    }
    // no transformation leading to endWord
    return 0;
};

// @param {string} word1
// @param {string} word2
// @return {bool}
function diffWords(word1, word2) {
    var diffCnt = 0;
    for (var i = 0; i < word1.length; i++) {
        if (word1[i] != word2[i]) {
            diffCnt++;
        }
        // different by more than 1 character
        if (diffCnt > 1) return false;
    }
    return true;
}