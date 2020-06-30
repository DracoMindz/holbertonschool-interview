#!/usr/bin/python3
"""
Recursive function that queries the Reddit API,
parses the title of all hot articles, and prints a sorted
count of given keywords.
"""
import requests
import sys


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
 if not hot_list
     return None
 try:
     req = request.get('https://www.reddit.com/r/{}/hot.json?limit=100&&'
                           'after={}".format(subreddit, a"fter), allow_redirects=False,'
                           'headers={'User-Agent':"morton"}).json()

# parse list
     # word_match is a list of words from word_list same length
     if word_match == {}:
          for wi in word_list:
              word_match[wi] = 0

     # parse the words in the data list
     for pos in range(len(req['data']['children'])):
         parWord_list = (req['data']['children'][pos]['data']['title']).split())

        # get the words from the word list
        for word in parWord_list:
            # apply this index wi for comparison
            # put all words in lowercase for comparison
            for wi in word_list:
                if wi.lower = word.lower:
                # if the words match add to word_match at location
                    word_match[wi] += 1
# order list


# print list


 except:
     pass