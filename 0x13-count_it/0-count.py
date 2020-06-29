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
    :param word_list: list of strings
    :return: word, word_count
    """
