/***************************************************************************
 *   Copyright (C) 2007 by Lothar May                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef CLIENTRIVER_H
#define CLIENTRIVER_H

#include <berointerface.h>
#include <boost/thread.hpp>

class HandInterface;


class ClientBeRoRiver : public BeRoInterface{
public:
	ClientBeRoRiver(HandInterface*, int, int, int, int);
	~ClientBeRoRiver();

	int getMyBeRoID() const;

	void setPlayersTurn(int theValue);
	int getPlayersTurn() const;
	
	void setHighestSet(int theValue);
	int getHighestSet() const;

	void setFirstRiverRound(bool theValue);
	bool getFirstRiverRound() const;

	void setSmallBlindPosition(int theValue);
	int getSmallBlindPosition() const;

	void setSmallBlind(int theValue);
	int getSmallBlind() const;

	void setHighestCardsValue(int theValue);
	int getHighestCardsValue() const;

	void resetFirstRun();

	void distributePot();

	void run();

	void preflopRun() {}
	void flopRun() {}
	void turnRun() {}
	void riverRun() {}
	void postRiverRun() {}

	void nextPlayer() {}

private:
	mutable boost::recursive_mutex m_syncMutex;

	HandInterface *myHand;

	int myID;
	int actualQuantityPlayers;	
	int dealerPosition;
	int smallBlindPosition;

	int smallBlind;
	int highestSet;

	bool firstRiverRun;
	bool firstRiverRound;
	int playersTurn;

	int highestCardsValue;

};

#endif

