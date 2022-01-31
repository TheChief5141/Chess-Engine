#include "defs.h"
#include "stdio.h"

char PceChar[] = ".PNBRQKpnbrqk";
char SideChar[] = "wb-";
char RankChar[] = "12345678";
char FileChar[] = "abcdefgh";

int PieceBig[13] = {FALSE, FALSE, TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, TRUE, TRUE, TRUE, TRUE, TRUE};
int PieceMaj[13] = {FALSE, FALSE, FALSE, FALSE, TRUE, TRUE, TRUE, FALSE, FALSE, FALSE, TRUE, TRUE, TRUE};
int PieceMin[13] = {FALSE, FALSE, TRUE, TRUE, FALSE, FALSE, FALSE, FALSE, TRUE, TRUE, FALSE, FALSE, FALSE};
int PieceVal[13] = {0, 100, 325, 325, 550, 100, 50000, 100, 325, 325, 550, 1000, 50000};
int PieceCol[13] = { BOTH, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK};

void PrintBoard(const S_BOARD *pos){
    int sq, file, rank, piece;

    printf("\nGame Board: \n\n");

    for(rank = RANK_8; rank >= RANK_1; rank--){
        printf("%d ",rank+1);
        for(file=FILE_A; file <= FILE_H; file++){
            sq = FR2SQ(file, rank);
            piece = pos->pieces[sq];
            printf("%3c", PceChar[piece]);
        }
        printf("\n");
    }

    printf("\n     ");
    for(file = FILE_A; file <= FILE_H; file++){
        printf("%3c", 'a'+file);
    }
    printf("\n");

    printf("\n");
    printf("side: %c\n", SideChar[pos->side]);
    printf("enPas: %d\n", pos->enPas);
    printf("castle: %c %c %c %c\n", 
        pos->castlePerm & WKCA ? 'K' : '-',
        pos->castlePerm & WQCA ? 'Q' : '-',
        pos->castlePerm & BKCA ? 'k' : '-', 
        pos->castlePerm & BQCA ? 'q' : '-',
    );
    printf("PosKey: %11x\n", pos->posKey);

}

