
#include "globals.h"
#include "GameState.h"
// function for play move

void playMove(GameState& game_state){

    if(game_state.get_gameBoard(game_state.get_selectedRow(),game_state.get_selectedColumn())== Empty){
        game_state.set_moveValid(true);
        game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), X);
        game_state.set_turn(true);


    }
    else{
        game_state.set_moveValid(false);
        game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), O);
        game_state.set_turn(false);
    }

    if(game_state.get_moveValid() == true){
        game_state.set_turn(false);
    }
    else{
        game_state.set_turn(true);
    }
    // 00 01, 02
    for(int i = 0; i <3 ; i++){
        if(game_state.get_gameBoard(0,i) == X ){
            game_state.set_winCode(1);
            game_state.set_gameOver(true);
        }
        else if(game_state.get_gameBoard(0,i) == O ){
            game_state.set_winCode(1);
            game_state.set_gameOver(true);
        }
        else{
            game_state.set_turn(false);
        }
    }

    for(int i = 0; i <3 ; i++){
        if(game_state.get_gameBoard(1,i) == X ){
            game_state.set_winCode(2);
            game_state.set_gameOver(true);
        }
        else if(game_state.get_gameBoard(1,i) == O ){
            game_state.set_winCode(2);
            game_state.set_gameOver(true);
        }
        else{
            game_state.set_turn(false);
        }
    }

    for(int i = 0; i <3 ; i++){
        if(game_state.get_gameBoard(2,i) == X ){
            game_state.set_winCode(3);
            game_state.set_gameOver(true);
        }
        else if(game_state.get_gameBoard(2,i) == O ){
            game_state.set_winCode(3);
            game_state.set_gameOver(true);
        }
        else{
            game_state.set_turn(false);
        }
    }

    for(int i = 0; i <3 ; i++){
        if(game_state.get_gameBoard(i,0) == X ){
            game_state.set_winCode(4);
            game_state.set_gameOver(true);
        }
        else if(game_state.get_gameBoard(i,0) == O ){
            game_state.set_winCode(4);
            game_state.set_gameOver(true);
        }
        else{
            game_state.set_turn(false);
        }
    }

    for(int i = 0; i <3 ; i++){
        if(game_state.get_gameBoard(i,1) == X){
            game_state.set_winCode(5);
            game_state.set_gameOver(true);
        }
        else if(game_state.get_gameBoard(i,1) == O ){
            game_state.set_winCode(5);
            game_state.set_gameOver(true);
        }
        else{
            game_state.set_turn(false);
        }
    }

    for(int i = 0; i <3 ; i++){
        if(game_state.get_gameBoard(i,2) == X ){
            game_state.set_winCode(6);
            game_state.set_gameOver(true);
        }
        else if(game_state.get_gameBoard(i,2) == O ){
            game_state.set_winCode(6);
            game_state.set_gameOver(true);
        }
        else{
            game_state.set_turn(false);
        }
    }









}











//
//
//void playMove(GameState& game_state) {
//    int i = game_state.get_selectedRow();
//    int j = game_state.get_selectedColumn();
//
//    if (game_state.get_gameBoard(i, j) == Empty) {
//
//        game_state.set_moveValid(true);
//
//        if (game_state.get_turn()) {
//            game_state.set_gameBoard(i, j, X);
//            game_state.set_turn(false);
//        } else {
//            game_state.set_gameBoard(i, j, O);
//            game_state.set_turn(true);
//        }
//        // varying row combinations  00 01 02, 10 11 12, 20 21 22
//
//        if ((game_state.get_gameBoard(i,0) == game_state.get_gameBoard(i,2))
//        && (game_state.get_gameBoard(i,0) == game_state.get_gameBoard(i,1))){
//            if(i == 0){
//                game_state.set_winCode(1);
//            }
//            else if (i == 1){
//                game_state.set_winCode(2);
//            }
//            else if (i == 2){
//                game_state.set_winCode(3);
//            }
//            game_state.set_gameOver(true);
//        }
//        // varying column combinations 00,20,10, 01,21,11, 02 22 12
//        else if ((game_state.get_gameBoard(0,j) == game_state.get_gameBoard(2,j))
//        && (game_state.get_gameBoard(0,j) == game_state.get_gameBoard(1,j))){
//            if(j == 0){
//                game_state.set_winCode(4);
//            }
//            else if (j == 1){
//                game_state.set_winCode(5);
//            }
//            else if(j==2){
//                game_state.set_winCode(6);
//            }
//            game_state.set_gameOver(true);
//        }
//        else if ( (i == j) && ((game_state.get_gameBoard(0,0) == game_state.get_gameBoard(2,2)
//        && game_state.get_gameBoard(0,0) == game_state.get_gameBoard(1,1)))){
//
//            game_state.set_winCode(7);
//            game_state.set_gameOver(true);
//        }
//        else if ((j + i == 2) && (game_state.get_gameBoard(0,2) == game_state.get_gameBoard(1,1)
//        && game_state.get_gameBoard(0,2) == game_state.get_gameBoard(2,0))){
//
//            game_state.set_winCode(8);
//            game_state.set_gameOver(true);
//        }
//
//        else{
//            game_state.set_winCode(0);
//
//            bool noWin = true;
//
//            for (int i=0;i<=2;i++){
//                for (int j=0;j<=2;j++){
//                    if (game_state.get_gameBoard(i,j) == 0){
//                        noWin = false;
//                        break;
//                    }
//                }
//
//            }
//
//            if (noWin){
//                game_state.set_gameOver(true);
//            }
//            else{
//                game_state.set_gameOver(false);
//            }
//
//
//        }
//    }
//
//    else{
//        game_state.set_winCode(0);
//        game_state.set_gameOver(false);
//        game_state.set_moveValid(false);
//
//
//    }
//
//
//
//
//}











//        // draw conditio
//        if ((i == j) && (game_state.get_gameBoard(0,0) == game_state.get_gameBoard(1,1))
//                 && (game_state.get_gameBoard(0,0) == game_state.get_gameBoard(2,2))) {
//            game_state.set_winCode(7);
//            game_state.set_gameOver(true);
//        }
//        if ((i + j == 2) && (game_state.get_gameBoard(2,0) == game_state.get_gameBoard(1,1))
//                 && (game_state.get_gameBoard(2,0) == game_state.get_gameBoard(0,2))) {
//            game_state.set_winCode(8);
//            game_state.set_gameOver(true);
//        }
//// 00 01 02 // for rows
//        if (i == 0) {
//                if(game_state.get_gameBoard(i,j) == game_state.get_gameBoard(i,0)
//                    && (game_state.get_gameBoard(i,j) == game_state.get_gameBoard(i,1))
//                    && (game_state.get_gameBoard(i,j) == game_state.get_gameBoard(i,2))
//                ){
//                    game_state.set_winCode(1);
//                    game_state.set_gameOver(true);
//                }
//        }
//        // 10 11 12
//        else if (i == 1) {
//            if((game_state.get_gameBoard(i,j) == game_state.get_gameBoard(i,0))
//               && (game_state.get_gameBoard(i,j) == game_state.get_gameBoard(i,1))
//               && ((game_state.get_gameBoard(i,j) == game_state.get_gameBoard(i,2)))
//                    ){
//                game_state.set_winCode(2);
//                game_state.set_gameOver(true);
//            }
//        }
//        // 20 21 22
//        else if (i == 2) {
//            if((game_state.get_gameBoard(i,j) == game_state.get_gameBoard(i,0))
//               && (game_state.get_gameBoard(i,j) == game_state.get_gameBoard(i,1))
//               && (game_state.get_gameBoard(i,j) == game_state.get_gameBoard(i,2))
//                    ){
//                game_state.set_winCode(3);
//                game_state.set_gameOver(true);
//            }
//        }
//        // 00 10 20  FOR columns
//         if (j == 0) {
//            if((game_state.get_gameBoard(i,j) == game_state.get_gameBoard(0,j))
//               && (game_state.get_gameBoard(i,j) == game_state.get_gameBoard(1,j))
//               && (game_state.get_gameBoard(i,j) == game_state.get_gameBoard(2,j))
//                    ){
//                game_state.set_winCode(4);
//                game_state.set_gameOver(true);
//            }
//
//        }
//        // 01 11 21
//        else if (j == 1) {
//            if((game_state.get_gameBoard(i,j) == game_state.get_gameBoard(0,j))
//               && (game_state.get_gameBoard(i,j) == game_state.get_gameBoard(1,j))
//               && (game_state.get_gameBoard(i,j) == game_state.get_gameBoard(2,j))
//                    ){
//                game_state.set_winCode(5);
//                game_state.set_gameOver(true);
//            }
//
//        }
//        // 02 12 22
//        else if (j == 2) {
//            if((game_state.get_gameBoard(i,j) == game_state.get_gameBoard(0,j))
//               && (game_state.get_gameBoard(i,j) == game_state.get_gameBoard(1,j))
//               && (game_state.get_gameBoard(i,j) == game_state.get_gameBoard(2,j))
//                    ){
//                game_state.set_winCode(6);
//                game_state.set_gameOver(true);
//            }
//
//        }
//        // draw
//        else {
//        for(int x = 0; x<= 2; x++){
//            for(int y = 0; y<= 2; y++){
//                if(game_state.get_gameBoard(x,y) != Empty){
//                    game_state.set_winCode(0);
//                    game_state.set_gameOver(true);
//                }
//                else{
//                    game_state.set_gameOver(false);
//                }
//            }
//        }
//        }
//


//        game_state.set_winCode(0);
//
//        bool noWin = true;
//        for(int x = 0; x<= 2; x++){
//            for(int y = 0; y<= 2; y++){
//                if(game_state.get_gameBoard(x,y) == 0){
//                    noWin = false;
//                    break;
//                }
//            }
//        }
//        if(noWin){
//            game_state.set_gameOver(true);
//        }
//        else {
//            game_state.set_gameOver(false);
//        }

//    }   // out of bounds
//    else{
//        game_state.set_moveValid(false);
//        game_state.set_gameOver(false);
//        game_state.set_winCode(0);
//
//    }
//
//}



            // varying row combinations
//        if ((game_state.get_gameBoard(i,0) == game_state.get_gameBoard(i,1)) &&
//        (game_state.get_gameBoard(i,0) == game_state.get_gameBoard(i,2))){
//            if(i == 0){
//                game_state.set_winCode(1);
//            }
//
//            else if (i == 1){
//                game_state.set_winCode(2);
//            }
//
//            else if(i == 2){
//                game_state.set_winCode(3);
//            }
//            game_state.set_gameOver(true);
//        }
//        else if ((game_state.get_gameBoard(0,j) == game_state.get_gameBoard(1,j))
//        && (game_state.get_gameBoard(0,j) == game_state.get_gameBoard(2,j))){
//
//            if(j == 0){
//                game_state.set_winCode(4);
//            }
//
//            else if (j == 1){
//                game_state.set_winCode(5);
//            }
//            else if(j == 2){
//                game_state.set_winCode(6);
//            }
//            game_state.set_gameOver(true);
//        }
//        else if ( (i==j) && game_state.get_gameBoard(0,0) == game_state.get_gameBoard(1,1)
//        && game_state.get_gameBoard(0,0) == game_state.get_gameBoard(2,2)){
//            game_state.set_winCode(7);
//            game_state.set_gameOver(true);
//        }
//        else if ((i + j == 2) && (game_state.get_gameBoard(0,2) == game_state.get_gameBoard(1,1) && game_state.get_gameBoard(0,2) == game_state.get_gameBoard(2,0))){
//            game_state.set_winCode(8);
//            game_state.set_gameOver(true);
//        }
//
//        else{
//            game_state.set_winCode(0);
//            //Check if draw or not
//
//            bool draw = true;
//            for (int i=0;i<3;i++){
//                for (int j=0;j<3;j++){
//                    if (game_state.get_gameBoard(i,j) == 0){
//                        draw = false;
//                        break;
//                    }
//                }
//
//            }
//
//            if (draw){
//                game_state.set_gameOver(true);
//            }
//            else{
//                game_state.set_gameOver(false);
//            }
//
//
//        }
//    }
//
//        //illegale moves result in no win, game is not over
//        else{
//            game_state.set_moveValid(false);
//            game_state.set_gameOver(false);
//            game_state.set_winCode(0);
//        }
//
//
//}


    /*
     * for(int col = 0; col <=3; col++){
            if(game_state.get_gameBoard(0,col) == game_state.get_gameBoard(0,0) &&
                    game_state.get_gameBoard(0,col) == game_state.get_gameBoard(0,1) &&
                    game_state.get_gameBoard(0,col) == game_state.get_gameBoard(0,2)) {
                game_state.set_winCode(1);
                game_state.set_gameOver(true);
            }

        }

        for(int col = 0; col <=3; col++){
            if(game_state.get_gameBoard(1,col) == game_state.get_gameBoard(1,0) &&
               game_state.get_gameBoard(1,col) == game_state.get_gameBoard(1,1) &&
               game_state.get_gameBoard(1,col) == game_state.get_gameBoard(1,2)) {
                game_state.set_winCode(2);
                game_state.set_gameOver(true);
            }
        }

        for(int col = 0; col <=3; col++){
            if(game_state.get_gameBoard(2,col) == game_state.get_gameBoard(2,0) &&
               game_state.get_gameBoard(2,col) == game_state.get_gameBoard(2,1) &&
               game_state.get_gameBoard(2,col) == game_state.get_gameBoard(2,2)) {
                game_state.set_winCode(3);
                game_state.set_gameOver(true);
            }
        }
        // for columns
        for(int row = 0; row <=3; row++){
            if(game_state.get_gameBoard(row,0) == game_state.get_gameBoard(0,0) &&
               game_state.get_gameBoard(row,0) == game_state.get_gameBoard(1,0) &&
               game_state.get_gameBoard(row,0) == game_state.get_gameBoard(2,0)) {
                game_state.set_winCode(4);
                game_state.set_gameOver(true);
            }

        }

        for(int row = 0; row <=3; row++){
            if(game_state.get_gameBoard(row,1) == game_state.get_gameBoard(0,1) &&
               game_state.get_gameBoard(row,1) == game_state.get_gameBoard(1,1) &&
               game_state.get_gameBoard(row,1) == game_state.get_gameBoard(2,1)) {
                game_state.set_winCode(5);
                game_state.set_gameOver(true);
            }
        }
        for(int row = 0; row <=3; row++){
            if(game_state.get_gameBoard(row,1) == game_state.get_gameBoard(0,2) &&
               game_state.get_gameBoard(row,1) == game_state.get_gameBoard(1,2) &&
               game_state.get_gameBoard(row,1) == game_state.get_gameBoard(2,2)) {
                game_state.set_winCode(6);
                game_state.set_gameOver(true);
            }
        }
            // Diagonal check
        if (( (i==j) && game_state.get_gameBoard(0,0) == game_state.get_gameBoard(1,1) && game_state.get_gameBoard(0,0) == game_state.get_gameBoard(2,2))
        ){
            game_state.set_winCode(7);
            game_state.set_gameOver(true);
        }
            // other diagonal check
       else if (( (i==j) && game_state.get_gameBoard(2,0) == game_state.get_gameBoard(1,1) && game_state.get_gameBoard(2,0) == game_state.get_gameBoard(0,2))
                ){
            game_state.set_winCode(8);
            game_state.set_gameOver(true);
        }

        else{ // Draw check: if board is empty for all combinations/positions
            game_state.set_winCode(0);
            bool noWin = true;
            for(int x = 0; x<= 2; x++){
                for(int y = 0; y<= 2; y++){
                    if(game_state.get_gameBoard(x,y) == 0){
                        noWin = false;
                        break;
                    }
                }
            }

            if(noWin){
                game_state.set_gameOver(true);
            }
            else{
                game_state.set_gameOver(false);
            }


        }


    }
     */






//void playMove(GameState& game_state) {
//    if(game_state.get_gameBoard(game_state.get_selectedRow(),game_state.get_selectedColumn()) == 0){
//        game_state.set_moveValid(true);
//
//        if(game_state.get_turn()){
//            game_state.set_gameBoard()
//        }
//
//
//
//
//    }
//    else{
//        game_state.set_moveValid(false);
//        return;
//    }
//
//    if(game_state.get_moveValid() == true){
//        if(game_state.get_turn() == true){
//            game_state.set_gameBoard(game_state.get_selectedRow(),game_state.get_selectedColumn(),X);
//            game_state.set_turn(false);
//        }
//        else{
//            game_state.set_gameBoard(game_state.get_selectedRow(),game_state.get_selectedColumn(),O);
//            game_state.set_turn(true);
//        }
//    }
//
//    int countX = 0;
//    int countO = 0;
//
////Top row XXX and OOO
//    for(int k = 0; k <= 3; k++){
//        if(game_state.get_gameBoard(0,k) == X){
//            countX++;
//        }
//        else if(game_state.get_gameBoard(0,k) == O){
//            countO++;
//        }
//        if(countX == 3 || countO == 3){
//            game_state.set_winCode(1);
//          //  game_state.set_gameOver(true);
//            return;
//        }
//
//    }
////Middle ROW XXX
//    for(int k = 0; k <= 3; k++){
//        if(game_state.get_gameBoard(1,k) == X){
//            countX++;
//        }
//        else if(game_state.get_gameBoard(1,k) == O){
//            countO++;
//        }
//        if(countX == 3 || countO == 3){
//            game_state.set_winCode(2);
//           // game_state.set_gameOver(true);
//            return;
//        }
//
//    }
/////Bottom Row XXX
//    for(int k = 0; k <= 3; k++){
//        if(game_state.get_gameBoard(2,k) == X){
//            countX++;
//        }
//        else if(game_state.get_gameBoard(2,k) == O){
//            countO++;
//        }
//        if(countX == 3 || countO == 3){
//            game_state.set_winCode(3);
//            //game_state.set_gameOver(true);
//            return;
//        }
//
//    }
/////Left Col XXX
//    for(int k = 0; k <= 3; k++){
//        if(game_state.get_gameBoard(k,0) == X){
//            countX++;
//        }
//        else if(game_state.get_gameBoard(k,0) == O){
//            countO++;
//        }
//        if(countX == 3 || countO == 3){
//            game_state.set_winCode(4);
//           // game_state.set_gameOver(true);
//            return;
//        }
//
//    }
//
//    //Middle Col XXX
//    for(int k = 0; k <= 3; k++){
//        if(game_state.get_gameBoard(k,1) == X){
//            countX++;
//        }
//        else if(game_state.get_gameBoard(k,1) == O){
//            countO++;
//        }
//        if(countX == 3 || countO == 3){
//            game_state.set_winCode(5);
//            //game_state.set_gameOver(true);
//            return;
//        }
//
//    }
//    //Last Col XXX
//    for(int k = 0; k <= 3; k++){
//        if(game_state.get_gameBoard(k,2) == X){
//            countX++;
//        }
//        else if(game_state.get_gameBoard(k,2) == O){
//            countO++;
//        }
//        if(countX == 3 || countO == 3){
//            game_state.set_winCode(6);
//            //game_state.set_gameOver(true);
//            return;
//        }
//
//    }
//    //00 -> 22 Diagonal
//    for(int k = 0; k <= 3; k++){
//        if(game_state.get_gameBoard(k,k) == X){
//            countX++;
//        }
//        else if(game_state.get_gameBoard(k,k) == O){
//            countO++;
//        }
//        if(countX == 2 || countO == 2){
//            game_state.set_winCode(7);
//            //game_state.set_gameOver(true);
//            return;
//        }
//
//    }
//        // right to left diagonal 2,0 - 0,2
//    if(game_state.get_gameBoard(2,0) && game_state.get_gameBoard(1,1) && game_state.get_gameBoard(0,2) == X){
//        game_state.set_winCode(8);
//        return;
//    }
//    if(game_state.get_gameBoard(2,0) && game_state.get_gameBoard(1,1) && game_state.get_gameBoard(0,2) == O){
//        game_state.set_winCode(8);
//        return;
//    }
//
//    countX = 0;
//    //for game draw
//    for(int i=0; i<=2; i++){
//        for(int j= 0; j<= 2; j++){
//            if(game_state.get_gameBoard(i,j) != Empty){
//                countX++;
//            }
//            if(countX==9){
//                game_state.set_winCode(0);
//                game_state.set_gameOver(true);
//                return;
//            }
//        }
//    }
//
//
//}
//
//// check if spot is empty, then change
