#!/usr/bin/python3
"""
Recursive function that queries the Reddit API,
parses the title of all hot articles, and prints a sorted (list)
count of given keywords.
"""
import collections
import requests
import sys
from requests import get


def count_words(subreddit, word_list, word_match={}, after=None):
    """
    recursive function parses titles and prints them in a sorted
    count of given key words
    Note: imported lIbraries must be in alphabetical order
    :param subreddit: posts dedicated to a specific topi people write about
                        on reddit
    :param word_list: list of words
    :after: next page
    :word_match: list of word frequency
    :return: word, word_count
    """
    # get list of hot articles
    if not word_list:
        return None
    try:
        req_data = request.get('https://www.reddit.com/r/{}/hot.'
                               'json?limit=100&&'
                               'after={}'.format(subreddit, after),
                               allow_redirects=False,
                               headers={'User-Agent': "morton"})
        if response.status_code != 200:
            return
        req = req_data.json()

        # parse list
        # word_match is a list of words from word_list same length
        if word_match == {}:
            for wi in word_list:
                word_match[wi] = 0
        after = req['data']['after']

        # parse the words in the data list
        for pos in range(len(req['data']['children'])):
            parWord_list = (req['data']['children'][pos]
                            ['data']['title']).split()

            # get the words from the word list
            for word in parWord_list:
                # apply this index wi for comparison
                # put all words in lowercase for comparison
                for wi in word_list:
                    if wi.lower == word.lower:
                        word_match[wi] += 1
        # order list
        if after is None:
            # choice here use dict or OrderedDict
            # OrderedDict keeps the order may be easier to iterate
            wordMatch_Dict = collections.OrderedDict(sorted(word_match.items(),
                                                            key=lambda x: x[1],
                                                            reverse=True))
            flag = 0
            for word, w_count in wordMatch_Dict.items():
                if w_count == 0:
                    flag += 1
                else:
                    print("{}: {}".format(word, w_count))
            if flag == len(wordMatch_Dict):
                print('/n')
            # recursive part
            else:
                count_words(subreddit, word_list, word_match={}, after=None)

    # print list
    except Exception:
        pass
