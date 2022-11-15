/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comique_de_ouf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:12:22 by dafranco          #+#    #+#             */
/*   Updated: 2022/06/19 16:23:50 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int arg_i;
  int val_i;
  char values[16];
  char s_vals;
  char ones_vals = 0;

  s_vals = 0;
  arg_i = 0;
  val_i = 0;
  if (argc == 2 && argv) {

    while (argv[1][arg_i] != '\0') {

      if (argv[1][arg_i] != ' ') {
        values[val_i] = argv[1][arg_i] - 48;
        if (values[val_i] == 1) {
          ones_vals++;
        }
        s_vals = s_vals + values[val_i];
        printf("s_vals=%d\n", s_vals);
        printf("val%d %d\n", val_i, values[val_i]); // debugging
        if (values[val_i] <= 0 || values[val_i] > 4 || val_i > 15) {
          write(2, "Invalide values or too much\n", 28);
          return 1;
        }
        if (s_vals > 38) {
          write(2, "impossible grid: s_vals>38\n", 27);
          return 1;
        }
        val_i++;
      }
      arg_i++;
    }

    if (val_i < 16) {
      write(2, "too few values\n", 27);
      return 1;
    }
    printf("ones_vals=%d s_vals=%d\n", ones_vals, s_vals);
    if (s_vals < 32 || ones_vals < 4) {
      write(2, "impossible grid: s_vals<32 or ones_vals<4\n", 41);
      return 1;
    }
    // debug et test 3*3=9:
    write(1, "\nvalid data\n",
          12); // ne doit pas etre afficher en cas de data non valide

  } else {
    write(2, "no values given or too much argv\n", 33);
    return 1;
  }

  char colup[] = {values[0], values[1], values[2], values[3]};
  char coldown[] = {values[4], values[5], values[6], values[7]};
  char rowleft[] = {values[8], values[9], values[10], values[11]};
  char rowright[] = {values[12], values[13], values[14], values[15]};

  char grid[4][4] = {{0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0}}; //{row1, row2, row3, row4}

  char zeros = 16;
  char fours_grid = 0;
  char threes_grid = 0;
  char twos_gride = 0;
  char ones_gride = 0;
  char fours_grid_m = 0;

  char c40 = 0;
  char c41 = 0;
  char c42 = 0;
  char c43 = 0;
  char c4s = 0;
  char l40 = 0;
  char l41 = 0;
  char l42 = 0;
  char l43 = 0;
  char l4s = 0;
  char l_val = -1;
  char c_val = -1;
  int c = -1;
  int l = -1;

  while (zeros != 0) // boucle infinie pour le moment.
  {
    if (ones_gride == 0) {
      // bord haut :
	}
	  if (colup[0] == 4 && coldown[0] == 1) {
        grid[0][0] = 1;
        grid[1][0] = 2;
        grid[2][0] = 3;
        grid[3][0] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      	if (colup[1] == 4 && coldown[1] == 1) {
		grid[0][1] = 1;
        grid[1][1] = 2;
        grid[2][1] = 3;
        grid[3][1] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (colup[2] == 4 && coldown[2] == 1) {
        grid[0][2] = 1;
        grid[1][2] = 2;
        grid[2][2] = 3;
        grid[3][2] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (colup[3] == 4 && coldown[3] == 1) {
        grid[0][3] = 1;
        grid[1][3] = 2;
        grid[2][3] = 3;
        grid[3][3] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
	  if (coldown[0] == 4 && colup[0] == 1) {
        grid[0][3] = 1;
        grid[0][2] = 2;
        grid[0][1] = 3;
        grid[0][0] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      	if (coldown[1] == 4 && colup[1] == 1) {
		grid[1][3] = 1;
        grid[1][2] = 2;
        grid[1][1] = 3;
        grid[1][0] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (coldown[2] == 4 && colup[2] == 1) {
        grid[2][3] = 1;
        grid[2][2] = 2;
        grid[2][1] = 3;
        grid[2][0] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (coldown[3] == 4 && colup[3] == 1) {
        grid[3][3] = 1;
        grid[3][2] = 2;
        grid[3][1] = 3;
        grid[3][0] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      // bord gauche :
	  
      if (rowleft[0] == 4 && rowright[0] == 1) {
        grid[0][0] = 1;
        grid[0][1] = 2;
        grid[0][2] = 3;
        grid[0][3] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (rowleft[1] == 4 && rowright[1] == 1) {
        grid[1][0] = 1;
        grid[1][1] = 2;
        grid[1][2] = 3;
        grid[1][3] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (rowleft[2] == 4 && rowright[2] == 1) {
        grid[2][0] = 1;
        grid[2][1] = 2;
        grid[2][2] = 3;
        grid[2][3] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (rowleft[3] == 4 && rowright[3] == 1) {
        grid[3][0] = 1;
        grid[3][1] = 2;
        grid[3][2] = 3;
        grid[3][3] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      // bord droit :
      if (rowright[0] == 4 && rowleft[0] == 1) {
        grid[0][3] = 1;
        grid[0][2] = 2;
        grid[0][1] = 3;
        grid[0][0] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (rowright[1] == 4 && rowleft[1] == 1) {
        grid[1][3] = 1;
        grid[1][2] = 2;
        grid[1][1] = 3;
        grid[1][0] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (rowright[2] == 4 && rowleft[2] == 1) {
        grid[2][3] = 1;
        grid[2][2] = 2;
        grid[2][1] = 3;
        grid[2][0] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (rowright[3] == 4 && rowleft[3] == 1) {
        grid[3][3] = 2;
        grid[3][2] = 1;
        grid[3][1] = 3;
        grid[3][0] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;

      }	 

// 3 --- 1
//
	  if (colup[0] == 3 && coldown[0] == 1) {
        grid[0][0] = 2;
        grid[1][0] = 1;
        grid[2][0] = 3;
        grid[3][0] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      	if (colup[1] == 3 && coldown[1] == 1) {
		grid[0][1] = 2;
        grid[1][1] = 1;
        grid[2][1] = 3;
        grid[3][1] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (colup[2] == 3 && coldown[2] == 1) {
        grid[0][2] = 2;
        grid[1][2] = 1;
        grid[2][2] = 3;
        grid[3][2] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (colup[3] == 3 && coldown[3] == 1) {
        grid[0][3] = 2;
        grid[1][3] = 1;
        grid[2][3] = 3;
        grid[3][3] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }

	    if (coldown[0] == 3 && colup[0] == 1) {
        grid[3][0] = 2;
        grid[2][0] = 1;
        grid[1][0] = 3;
        grid[0][0] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (coldown[1] == 3 && colup[1] == 1) {
        grid[3][1] = 2;
        grid[2][1] = 1;
        grid[1][1] = 3;
        grid[0][1] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (coldown[2] == 3 && colup[2] == 1) {
        grid[3][2] = 2;
        grid[2][2] = 1;
        grid[1][2] = 3;
        grid[0][2] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (coldown[3] == 3 && colup[3] == 1) {
        grid[3][3] = 2;
        grid[2][3] = 1;
        grid[1][3] = 3;
        grid[0][3] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      // bord gauche :
      if (rowleft[0] == 3 && rowright[0] == 1) {
        grid[0][0] = 2;
        grid[0][1] = 1;
        grid[0][2] = 3;
        grid[0][3] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (rowleft[1] == 3 && rowright[1] == 1) {
        grid[1][0] = 2;
        grid[1][1] = 1;
        grid[1][2] = 3;
        grid[1][3] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (rowleft[2] == 3 && rowright[2] == 1) {
        grid[2][0] = 2;
        grid[2][1] = 1;
        grid[2][2] = 3;
        grid[2][3] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }      // bord gauche :

		if (rowleft[3] == 3 && rowright[3] == 1) {
        grid[3][0] = 2;
        grid[3][1] = 1;
        grid[3][2] = 3;
        grid[3][3] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      // bord droit :
      if (rowright[0] == 3 && rowleft[0] == 1) {
        grid[0][3] = 2;
        grid[0][2] = 1;
        grid[0][1] = 3;
        grid[0][0] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (rowright[1] == 3 && rowleft[1] == 1) {
        grid[1][3] = 2;
        grid[1][2] = 1;
        grid[1][1] = 3;
        grid[1][0] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (rowright[2] == 3 && rowleft[2] == 1) {
        grid[2][3] = 2;
        grid[2][2] = 1;
        grid[2][1] = 3;
        grid[2][0] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (rowright[3] == 3 && rowleft[3] == 1) {
        grid[3][3] = 2;
        grid[3][2] = 1;
        grid[3][1] = 3;
        grid[3][0] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }

	  if (colup[0] == 3 && coldown[0] == 2) {
        grid[2][0] = 4;

      }
      	if (colup[1] == 3 && coldown[1] == 2) {
        grid[2][1] = 4;
     }

      if (colup[2] == 3 && coldown[2] == 1) {
        grid[2][2] = 4;
             
	  }
      if (colup[3] == 3 && coldown[3] == 1) {
        grid[2][3] = 4;        
	  }

	    if (coldown[0] == 3 && colup[0] == 1) {
        grid[3][0] = 2;
        grid[2][0] = 1;
        grid[1][0] = 3;
        grid[0][0] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (coldown[1] == 3 && colup[1] == 1) {
        grid[3][1] = 2;
        grid[2][1] = 1;
        grid[1][1] = 3;
        grid[0][1] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (coldown[2] == 3 && colup[2] == 1) {
        grid[3][2] = 2;
        grid[2][2] = 1;
        grid[1][2] = 3;
        grid[0][2] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (coldown[3] == 3 && colup[3] == 1) {
        grid[3][3] = 2;
        grid[2][3] = 1;
        grid[1][3] = 3;
        grid[0][3] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      // bord gauche :
      if (rowleft[0] == 3 && rowright[0] == 1) {
        grid[0][0] = 2;
        grid[0][1] = 1;
        grid[0][2] = 3;
        grid[0][3] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (rowleft[1] == 3 && rowright[1] == 1) {
        grid[1][0] = 2;
        grid[1][1] = 1;
        grid[1][2] = 3;
        grid[1][3] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (rowleft[2] == 3 && rowright[2] == 1) {
        grid[2][0] = 2;
        grid[2][1] = 1;
        grid[2][2] = 3;
        grid[2][3] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }      // bord gauche :

		if (rowleft[3] == 3 && rowright[3] == 1) {
        grid[3][0] = 2;
        grid[3][1] = 1;
        grid[3][2] = 3;
        grid[3][3] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      // bord droit :
      if (rowright[0] == 3 && rowleft[0] == 1) {
        grid[0][3] = 2;
        grid[0][2] = 1;
        grid[0][1] = 3;
        grid[0][0] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (rowright[1] == 3 && rowleft[1] == 1) {
        grid[1][3] = 2;
        grid[1][2] = 1;
        grid[1][1] = 3;
        grid[1][0] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (rowright[2] == 3 && rowleft[2] == 1) {
        grid[2][3] = 2;
        grid[2][2] = 1;
        grid[2][1] = 3;
        grid[2][0] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }
      if (rowright[3] == 3 && rowleft[3] == 1) {
        grid[3][3] = 2;
        grid[3][2] = 1;
        grid[3][1] = 3;
        grid[3][0] = 4;
        ones_gride++;
        twos_gride++;
        threes_grid++;
        fours_grid++;
      }


      fours_grid_m = fours_grid;
      printf("o_g:%d, t_g:%d, th_g:%d f_g: %d\n", ones_gride, twos_gride,
             threes_grid, fours_grid);
      if (ones_vals > 4 || twos_gride > 4 || threes_grid > 4 ||
          fours_grid > 4) {
        write(2, "impossible grid: too much n_grid\n", 37);
        return 1;
      }
      printf("zeros = %d\n", zeros);
      zeros = zeros - fours_grid - threes_grid - twos_gride - ones_gride;
      printf("zeros - f_g - th_g - t_g - o_g = %d\n", zeros);
    }
    if (zeros <= 16) {
      // coin :
      if (colup[0] == 1 && rowleft[0] == 1 && grid[0][0]) {
        grid[0][0] = 4;
        fours_grid++;
      }
      if (colup[3] == 1 && rowright[0] == 1 && grid[0][3]) {
        grid[0][3] = 4;
        fours_grid++;
      }
      if (coldown[0] == 1 && rowleft[3] == 1 && grid[3][0]) {
        grid[3][0] = 4;
        fours_grid++;
      }
      if (coldown[3] == 1 && rowright[3] == 1 && grid[3][3]) {
        grid[3][3] = 4;
        fours_grid++;
      }
      // diag :
      if (grid[3][0] == 4 && grid[0][3] == 4 && rowleft[1] == 3 &&
          grid[1][2] == 0 && grid[2][1] == 0) {
        grid[1][2] = 4;
        grid[2][1] = 4;
        fours_grid = fours_grid + 2;
      }
      if (grid[0][0] == 4 && grid[3][3] == 4 && rowleft[1] == 2 &&
          grid[1][2] == 0 && grid[2][1] == 0) {
        grid[1][1] = 4;
        grid[2][2] = 4;
        fours_grid = fours_grid + 2;
      }
      // bord haut :
      if (colup[0] == 1 && grid[0][0] != 4) {
        grid[0][0] = 4;
        fours_grid++;
      }
      if (colup[1] == 1 && grid[0][1] != 4) {
        grid[0][1] = 4;
        fours_grid++;
      }
      if (colup[2] == 1 && grid[0][2] != 4) {
        grid[0][2] = 4;
        fours_grid++;
      }
      if (colup[3] == 1 && grid[0][3] != 4) {
        grid[0][3] = 4;
        fours_grid++;
      }
      // bord gauche :
      if (rowleft[0] == 1 && grid[0][0] != 4) {
        grid[0][0] = 4;
        fours_grid++;
      }
      if (rowleft[1] == 1 && grid[1][0] != 4) {
        grid[1][0] = 4;
        fours_grid++;
      }
      if (rowleft[2] == 1 && grid[2][0] != 4) {
        grid[2][0] = 4;
        fours_grid++;
      }
      if (rowleft[3] == 1 && grid[3][0] != 4) {
        grid[3][0] = 4;
        fours_grid++;
      }
      // bord droit :
      if (rowright[0] == 1 && grid[0][3] != 4) {
        grid[0][3] = 4;
        fours_grid++;
      }
      if (rowright[1] == 1 && grid[1][3] != 4) {
        grid[1][3] = 4;
        fours_grid++;
      }
      if (rowright[2] == 1 && grid[2][3] != 4) {
        grid[2][3] = 4;
        fours_grid++;
      }
      if (rowright[3] == 1 && grid[3][3] != 4) {
        grid[3][3] = 4;
        fours_grid++;
      }
      // bord bas :
      if (coldown[0] == 1 && grid[3][0] != 4) {
        grid[3][0] = 4;
        fours_grid++;
      }
      if (coldown[1] == 1 && grid[3][1] != 4) {
        grid[3][1] = 4;
        fours_grid++;
      }
      if (coldown[2] == 1 && grid[3][2] != 4) {
        grid[3][2] = 4;
        fours_grid++;
      }
      if (coldown[3] == 1 && grid[3][3] != 4) {
        grid[3][3] = 4;
        fours_grid++;
      }
      // interpole :
      if (fours_grid == 3 && ones_gride == 0 && twos_gride == 0 &&
          threes_grid == 0)	{

        l40 = grid[0][0] + grid[0][1] + grid[0][2] + grid[0][3];
        l41 = (grid[1][0] + grid[1][1] + grid[1][2] + grid[1][3]) * 2;
        l42 = (grid[2][0] + grid[2][1] + grid[2][2] + grid[2][3]) * 3;
        l43 = (grid[3][0] + grid[3][1] + grid[3][2] + grid[3][3]) * 4;
        l4s = l40 + l41 + l42 + l43;
        printf("sum_polynomes_lines = %d\n", l4s);
        if (l4s == 36) {
          l = 0;
        }
        if (l4s == 32) {
          l = 1;
        }
        if (l4s == 28) {
          l = 2;
        }
        if (l4s == 24) {
          l = 3;
        }

        c43 = (grid[0][3] + grid[1][3] + grid[2][3] + grid[3][3]) * 4;
        c42 = (grid[0][2] + grid[1][2] + grid[2][2] + grid[3][2]) * 3;
        c41 = (grid[0][1] + grid[1][1] + grid[2][1] + grid[3][1]) * 2;
        c40 = grid[0][0] + grid[1][0] + grid[2][0] + grid[3][0];
        c4s = c40 + c41 + c42 + c43;
        printf("sum_polygones_cols = %d\n", c4s);
        if (c4s == 36) {
          c = 0;
        }
        if (c4s == 32) {
          c = 1;
        }
        if (c4s == 28) {
          c = 2;
        }
        if (c4s == 24) {
          c = 3;
        }

        if (grid[l][c] != 4) {
          grid[l][c] = 4;
          fours_grid++;

        } else {
          write(2, "go into interpole was a mistake\n", 32);
          return (1);
        }

        l40 = 0;
        l41 = 0;
        l42 = 0;
        l43 = 0;
        l4s = 0;

        c40 = 0;
        c41 = 0;
        c42 = 0;
        c43 = 0;
        c4s = 0;

        l = -1;
        c = -1;
      }

      fours_grid = fours_grid - fours_grid_m;
      fours_grid_m = fours_grid;

      printf("o_g:%d, t_g:%d, th_g:%d, f_g:%d\n", ones_gride, twos_gride,
             threes_grid, fours_grid);
      if (fours_grid > 4) {
        write(2, "impossible grid: too much fours_grid\n", 37);
        return 1;
      }
      printf("zeros = %d\n", zeros);
      zeros = zeros - fours_grid;
      printf("zeros - f_g = %d\n", zeros);

      // interpaupaule :
      l40 = grid[0][0] + grid[0][1] + grid[0][2] + grid[0][3];
      l41 = grid[1][0] + grid[1][1] + grid[1][2] + grid[1][3];
      l42 = grid[2][0] + grid[2][1] + grid[2][2] + grid[2][3];
      l43 = grid[3][0] + grid[3][1] + grid[3][2] + grid[3][3];
      l4s = l40 + l41 + l42 + l43;
      printf("sum_lines = %d\n", l4s);

      c43 = grid[0][3] + grid[1][3] + grid[2][3] + grid[3][3];
      c42 = grid[0][2] + grid[1][2] + grid[2][2] + grid[3][2];
      c41 = grid[0][1] + grid[1][1] + grid[2][1] + grid[3][1];
      c40 = grid[0][0] + grid[1][0] + grid[2][0] + grid[3][0];
      c4s = c40 + c41 + c42 + c43;
      printf("sum_cols = %d\n", c4s);
      if (c4s == 9) {
        c_val = 1;
      }
      if (c4s == 8) {
        c_val = 2;
      }
      if (c4s == 7) {
        c_val = 3;
      }
      if (c4s == 6) {
        c_val = 4;
      }

      if (c40 == 0) {
        c = 0;
      }
      if (c41 == 0) {
        c = 1;
      }
      if (c42 == 0) {
        c = 2;
      }
      if (c43 == 0) {
        c = 3;
      }

      if (l4s == 9) {
        l_val = 1;
      }
      if (l4s == 8) {
        l_val = 2;
      }
      if (l4s == 7) {
        l_val = 3;
      }
      if (l4s == 6) {
        l_val = 4;
      }

      if (l40 == 0) {
        l = 0;
      }
      if (l41 == 0) {
        l = 1;
      }
      if (l42 == 0) {
        l = 2;
      }
      if (l43 == 0) {
        l = 3;
      }
      // faux mais pour que cela compile et que j'aille dormir
      // !!!!!!!!!<-lis!!!!!!!!!!!! :
      if (l != -1 && c != -1 && grid[l][c] == 0) {
        grid[l][c] = l_val + c_val;
      }
    }

    break; // break de debug pour ne pas infinite loop
  }

  // affichage :
  int i = 0;
  int j = 0;

  while (i < 4) {
    j = 0;
    while (j < 4) {
      if (j == 3) {
        printf("%d", grid[i][j]);
      } else
        printf("%d ", grid[i][j]);
      j++;
    }
    printf("\n");
    i++;
  }

 
 return (0);
}
