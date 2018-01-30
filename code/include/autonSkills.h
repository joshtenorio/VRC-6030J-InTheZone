#pragma once

/**
 * Goes forward, picks up mobile goal by the stationary goal, drops it in the 20 pt zone,
 * takes other closest mobile goal by stationary goal and puts it in 10 pt zone, if there is 
 * still time then take the other mobile goals closest to stationary goal and drop it in other
 * 20 pt zone and/or 10 pt zone
 */
void autoSkills();

/**
 * Goes forward gets side mobile goal by parking square and scores in 20, gets mob goal by
 * stat goal and scores in 10 pt zone and moves away. 30 pts max
 */
void autoBetterSkills();