"""This module contains code from
Think Python by Allen B. Downey
http://thinkpython.com

Copyright 2012 Allen B. Downey
License: GNU GPLv3 http://www.gnu.org/licenses/gpl.html

"""

from Card import Deck, Hand, Card
from sets import Set
from collections import defaultdict


class PokerHand(Hand):

    def suit_hist(self):
        """Builds a histogram of the suits that appear in the hand.

        Stores the result in attribute suits.
        """
        self.suits = {}
        for card in self.cards:
            self.suits[card.suit] = self.suits.get(card.suit, 0) + 1

    def rank_hist(self):
        """Builds a histogram of the suits that appear in the hand.

        Stores the result in attribute suits.
        """
        self.ranks = {}
        for card in range(1, 13):
            self.ranks[card] = 0
        for card in self.cards:
            self.ranks[card.rank] = self.ranks.get(card.rank, 0) + 1

    def has_flush(self):
        """
            Returns True if the hand has a flush else False.
            Note: Works with Hands with cards >= 5
        """
        self.suit_hist()
        for val in self.suits.values():
            if val >= 5:
                return True
        return False
        
    def has_pair(self):
        """
            Returns True if the hand has a pair else False.
        """
        self.rank_hist()
        for val in self.ranks.values():
            if val >= 2:
                return True
        return False;
        
    def has_twoPair(self):
        """
            Returns True if the hand has Two pairs else False.
        """
        self.rank_hist()
        ctr = 0
        for val in self.ranks.values():
            if val >= 2:
                ctr += val/2
        if(ctr >= 2):
            return True
        return False
        
    def has_threeOfKind(self):
        """
            Returns True if the hand has Three of a Kind else False.
        """
        self.rank_hist()
        for val in self.ranks.values():
            if val >= 3:
                return True
        return False

    def has_straight(self):
        """
            Returns True if the hand has a Straight else False.
        """
        self.rank_hist()
        in_seq_cards = 0
        for key, val in self.ranks.iteritems():
            if val > 0:
                in_seq_cards += 1
            else:
                in_seq_cards = 0
            if in_seq_cards >= 5:
                return True

        return False

    def has_fullHouse(self):
        """
            Returns True if the hand has a full house else False.
        """
        self.rank_hist()
        pairs = 0
        triplets = 0
        for val in self.ranks.values():
            if val >= 3:
                triplets += 1
            elif val >= 2:
                pairs += 1
        if triplets > 0 and pairs > 0:
            return True
        return False

    def has_fourOfKind(self):
        self.rank_hist()
        for val in self.ranks.values():
            if val >= 4:
                return True
        return False

    def has_straightFlush(self):
        cur_cards = defaultdict(list)
        for card in self.cards:
            cur_cards[card.suit].append(card)
        
        for suits, cards in cur_cards.iteritems():
            if len(cards) >= 5:
                dummy_hand = PokerHand()
                dummy_hand.cards = cards
                if dummy_hand.has_straight():
                    return True
            
        return False

    def classify(self):
        if self.has_straightFlush():
            return 'Straight Flush'
        if self.has_fourOfKind():
            return 'Four of a Kind'
        if self.has_fullHouse():
            return 'Full House'
        if self.has_flush():
            return 'Flush'
        if self.has_straight():
            return 'Straight'
        if self.has_threeOfKind():
            return 'Three of a Kind'
        if self.has_twoPair():
            return 'Two Pair'
        if self.has_pair():
            return 'Pair'


# if __name__ == '__main__':
#     # make a deck
#     deck = Deck()
#     deck.shuffle()

#     # deal the cards and classify the hands
#     for i in range(7):
#         hand = PokerHand()
#         deck.move_cards(hand, 7)
#         hand.sort()
#         print hand
#         print hand.has_flush()
#         print ''

def single_run(hands={}):
    deck = Deck()
    deck.shuffle()

    # deal the cards and classify the hands
    for i in range(7):
        hand = PokerHand()
        deck.move_cards(hand, 7)
        hand.sort()
        classification = str(hand.classify())
        hands[classification] = hands.get(classification, 0) + 1

    return hands


def print_probabilities(hands):

    total = 0

    for val in hands:
        total += hands[val]

    print 'Poker Probabilities'

    for val in hands:
        hands[val] = (hands[val] / float(total)) * 100

    for key in sorted(hands, key=hands.get, reverse=False):
        print '%s: %.2f %%' % (key, hands[key])

if __name__ == '__main__':
    # make a deck
    deck = Deck()
    deck.shuffle()

    # deal the cards and classify the hands
    for i in range(2000):
        hands = single_run()

    print_probabilities(hands)