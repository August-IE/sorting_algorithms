#include "deck.h"

/**
 * _strcmp - compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 * Return: 0 if s1 == s2 or otherwise.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}
/**
 * find_value - find the numerical value of a card.
 * @card: pointer to the deck_node_t card.
 * Return: The numerical value of the card.
*/
char find_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (7);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_deck_sort_kind - sorts a deck of cards from spade to diamond.
 * @deck: pointer to the head of a deck_node_t.
 *
 */
void insertion_deck_sort_kind(deck_node_t **deck)
{
	deck_node_t *iterate, *insert, *tmp;
	for (iterate = (*deck)->next; iterate != NULL; iterate = tmp)
	{
		tmp = iterate->next;
		insert = iterate->prev;
		while (insert != NULL && iterate->card->kind < insert->card->kind)
		{
			insert->next = iterate->next;
			if (iterate->next != NULL)
				iterate->next->prev = insert;
			iterate->prev = insert->prev;
			iterate->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iterate;
			else
				*deck = iterate;
			insert->prev = iterate;
			insert = iterate->prev;
		}
	}
}

/**
 * insertion_deck_sort_value - sorts a deck of cards sorted from ace to king.
 * @deck: pointer to the head of a deck_node_t.
 *
 */
void insertion_deck_sort_value(deck_node_t **deck)
{
	deck_node_t *iterate, *insert, *tmp;
	for (iterate = (*deck)->next; iterate != NULL; iterate = tmp)
	{
		tmp = iterate->next;
		insert = iterate->prev;
		while (insert != NULL && find_value(iterate) < find_value(insert)
				&& iterate->card->kind < insert->card->kind)
		{
			insert->next = iterate->next;
			if (iterate->next != NULL)
				iterate->next->prev = insert;
			iterate->prev = insert->prev;
			iterate->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iterate;
			else
				*deck = iterate;
			insert->prev = iterate;
			insert = iterate->prev;

		}
	}
}

/**
 * sort_deck - sort a decck of cards.
 *
 * @deck: pointer to the head.
 *
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	insertion_deck_sort_kind(deck);
	insertion_deck_sort_value(deck);
}
