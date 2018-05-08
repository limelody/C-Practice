//Melody Li Assignment 9 Question 1
#include <iostream>
#include <stdlib.h>     // rand
#include <time.h>       // time

using namespace std;

/*
The maximum number of cards a hand could hold is 52. This is when a player
is playing a single player game (ex. solitaire) and uses the entire deck, which
consists of 52 cards.

The Class must store the hand size(the number of cards the player can hold in
that game), and include an array from the Card Class to store each individual
card they are dealt).
*/

enum Suit {NONE, CLUBS, HEARTS, DIAMONDS, SPADES};

const int MAX_HAND_SIZE = 52;

class Card
{
public:
    int value;
    Suit suit;
};

class CardHand
{
private:

    Card cards_in_hand[MAX_HAND_SIZE];
    int handSize;

    void sortCards()
    {

        for (int pass = 0; pass < handSize; pass++)
        {
            Card cardMax = cards_in_hand[pass];
            int maxIndex = pass;

            for (int check = pass + 1; check < handSize; check++)
            {
                if (cards_in_hand[check].value > cardMax.value)
                {
                    cardMax = cards_in_hand[check];
                    maxIndex = check;
                }

                else if(cards_in_hand[check].value == cardMax.value)
                    if (cards_in_hand[check].suit > cardMax.suit)
                    {
                        cardMax = cards_in_hand[check];
                        maxIndex = check;
                    }
            }

            cards_in_hand[maxIndex] = cards_in_hand[pass];
            cards_in_hand[pass] = cardMax;
        }
    }


public:

    int GetHandSize() const;

    bool AddCard(Card new_card);

    CardHand()
    {
        handSize = 5;
        for (int index = 0; index < handSize; index++)
            cards_in_hand[index].value = -1;
    }

    CardHand(int wanted_handSize)
    {
        if (wanted_handSize > MAX_HAND_SIZE || wanted_handSize < 0)
            handSize = 5;

        else
            handSize = wanted_handSize;

        for (int cardInHand = 0; cardInHand < handSize; cardInHand++)
        {
            cards_in_hand[cardInHand].value = -1;
            cards_in_hand[cardInHand].suit = NONE;
        }
    }

    int betterHand (CardHand other_hand)
    {
        //Hands are compared by adding up the values, largest sum is best hand
        int sum_this = 0, sum_other_hand = 0;
        for (int check_this = 0; check_this < handSize; check_this++)
        {
            sum_this += cards_in_hand[check_this].value;
        }

        for (int check_other = 0; check_other < handSize; check_other++)
        {
            sum_other_hand += other_hand.cards_in_hand[check_other].value;
        }

        if (sum_this > sum_other_hand)
            return 1;

        else if (sum_other_hand > sum_this)
            return -1;

        else
            return 0;
    }

    void printHand(ostream &out)
    {
        sortCards();
        out << "start of hand" << endl;

        for (int out_this_index = 0; out_this_index < handSize;
             out_this_index++)
        {
            if (cards_in_hand[out_this_index].value == 1)
                out << "A ";
            else if (cards_in_hand[out_this_index].value == 11)
                out << "J ";
            else if (cards_in_hand[out_this_index].value == 12)
                out << "Q ";
            else if (cards_in_hand[out_this_index].value == 13)
                out << "K ";
            else
                out << cards_in_hand[out_this_index].value << " ";


            if (cards_in_hand[out_this_index].suit == CLUBS)
                out << "CLUBS" << endl;
            else if (cards_in_hand[out_this_index].suit == DIAMONDS)
                out << "DIAMONDS" << endl;
            else if (cards_in_hand[out_this_index].suit == HEARTS)
                out << "HEARTS" << endl;
            else
                out << "SPADES" << endl;

        }
        out << "end of hand" << endl << endl;
	}
};

bool DealCards(CardHand hands[], int num_hands)
{
    // check if there are enough cards (only 52 cards available)
    int cards_needed = 0;
    for (int hand_index = 0; hand_index < num_hands; hand_index++)
    {
        cards_needed += hands[hand_index].GetHandSize();
    }
    if (cards_needed > 52)
        return false;

    const int NUM_CARDS = 52;
    Card deck[NUM_CARDS];
    int current_value = 1;
    Suit current_suit = CLUBS;

    // create the deck of cards
    for (int card_index = 0; card_index < NUM_CARDS; card_index++)
    {
        deck[card_index].value = current_value;
        deck[card_index].suit = current_suit;

        current_value++;
        if (current_value > 13)
        {
            switch (current_suit)
            {
                case CLUBS: current_suit = HEARTS;
                    break;
                case HEARTS: current_suit = DIAMONDS;
                    break;
                case DIAMONDS: current_suit = SPADES;
                    break;
                default: break;
            }
            current_value = 1;
        }
    }

    // seed the random number generator
    srand(time(NULL));

    // randomly pull cards from the deck and assign them to each hand
    for (int hand_index = 0; hand_index < num_hands; hand_index++)
    {
        for (int card_index = 0; card_index < hands[hand_index].GetHandSize(); card_index++)
        {
            Card assign_card;
            assign_card.value = 0;
            assign_card.suit = NONE;

            while (assign_card.value == 0)
            {
                int try_card = rand() % 52;

                if (deck[try_card].value > 0)
                {
                    assign_card.value = deck[try_card].value;
                    assign_card.suit = deck[try_card].suit;
                    deck[try_card].value = 0;
                    deck[try_card].suit = NONE;
                }
            }

            hands[hand_index].AddCard(assign_card);
        }
    }

    return true;
}

/**********************main function*********************************/
int main()
{
    const int N_PEOPLE = 4;

    CardHand person0, person1, person2, person3;

    CardHand all_hands[N_PEOPLE] = {person0, person1, person2, person3};

    DealCards(all_hands, N_PEOPLE);

    for (int person = 0; person < N_PEOPLE; person++)
    {
        all_hands[person].printHand(cout);
    }

    int bestPerson = 0;
    for (int check_person = 1; check_person < N_PEOPLE; check_person++)
    {
        if (all_hands[check_person].betterHand(all_hands[bestPerson]) == 1)
            bestPerson = check_person;
    }

    cout << "BEST HAND" << endl << "Player" << bestPerson+1 << endl;
    all_hands[bestPerson].printHand(cout);

    return 0;
}

int CardHand::GetHandSize() const
{
    return handSize;
}

bool CardHand::AddCard(Card new_card)
{
    for (int check_card = 0; check_card < handSize; check_card++)
        if (cards_in_hand[check_card].value == -1)
        {
            cards_in_hand[check_card] = new_card;
            sortCards();
            return true;
        }

    return false;
}

/*
start of hand
K SPADES
J DIAMONDS
7 DIAMONDS
5 CLUBS
4 SPADES
end of hand

start of hand
K HEARTS
6 SPADES
6 CLUBS
3 SPADES
3 HEARTS
end of hand

start of hand
Q SPADES
J CLUBS
10 HEARTS
9 SPADES
A SPADES
end of hand

start of hand
10 DIAMONDS
5 DIAMONDS
5 HEARTS
2 HEARTS
A DIAMONDS
end of hand

BEST HAND
Player3
start of hand
Q SPADES
J CLUBS
10 HEARTS
9 SPADES
A SPADES
end of hand


Process returned 0 (0x0)   execution time : 0.214 s
Press any key to continue.
*/
