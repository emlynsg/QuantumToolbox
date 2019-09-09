//
// Created by Emlyn Graham on 9/08/19.
// Main tests all aspects of the Quantum Toolbox library
//
#include <vector>


#include "Grid.h"
#include "Wavefunction.h"
#include "Potential.h"
#include "System.h"
#include "Plotter.h"

//#define EIGEN_RUNTIME_NO_MALLOC

using namespace Eigen;
using namespace std;

int main() {
//  Eigen::internal::set_is_malloc_allowed(false);
/// TODO: Fix System so you can add potentials and wavefunctions freely
/// Currently need to add wavefunctions first
  unsigned int sizeN = 1023;
  double xmin = -150.0;
  double xmax = 150.0;
  double kscale = 1.0;
  Grid grid(sizeN, xmin, xmax, kscale);
  double ReducedMass = 1.0;
  Wavefunction wavefunction(grid, ReducedMass);
  wavefunction.initGaussian(-100.0, 10.0);
  wavefunction.boostEnergy(80.0);
  Potential potential(grid);
  potential.initZero();
  potential.addGaussian(0.0, 80.0, 5.0);
//  potential.addGaussian(100.0, -80.0*i, 10.0);
  System system(wavefunction, potential);

  // Taylor Evolution
  Plotter plot(system);
  plot.animate(100000, 0.1, 20, 100);

  // CC Evolution
//  system.initCC(0.1);
//  Plotter plot(system);
//  plot.animateCC(100000, 100);
  return 0;

}

