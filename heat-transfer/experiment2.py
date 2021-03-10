import math
from iapws.iapws95 import IAPWS95

def compute(T_initial, T_infinity, length, diameter, n):
    # Convert temperatures to Kelvin
    T_initial = T_initial + 273.15
    T_infinity = T_infinity + 273.15

    # print("Iteration\tt(s) \t   h (W/m^2*K)\t\ty")

    # Initialise T_next to T_initial
    T_next = T_initial
    
    for i in range(1, 3):
        t = i * 20 # (s) time
        T_film = (T_next + T_infinity) / 2

        water = IAPWS95(T=T_film, x=0)
        beta = water.alfav # (1/K) Isothermal Expansion Coefficient
        nu = water.nu # (m^2/s) Kinematic Viscosity
        k = water.k # (W/m*K) Thermal Conductivity
        Pr = water.Prandt # Prandtl number
        g = 9.81 # (m/s^2) Gravity
        L = length # (m) Length

        Gr = g * beta * (T_infinity - T_next) * L**3 / nu**2 # Grashof Number
        Ra = Gr * Pr # Rayleigh Number
        Nu = 0.1 * Ra**(1/3) # Nusselt Number

        # Convective Heat Transfer Coefficient
        h = Nu * k / L

        print("\nIteration ", i)
        print("beta = {:.2e}".format(beta))
        print("nu = {:.2e}".format(nu))
        print("k = {:.2e}".format(k))
        print("Pr = {:.2e}".format(Pr))
        print("Gr = {:.2e}".format(Gr))
        print("Ra = {:.2e}".format(Ra))
        print("Nu = {:.2e}".format(Nu))
        print("h = {:.2e}".format(h))

        # Values to be plotted on the y-axis
        y = (T_next - T_infinity) / (T_initial - T_infinity)

        # print("{}\t\t{}\t{}\t{}".format(i,t-20,h,y), end="")
        # print("\t\t\tTurbulent Flow" if Ra > 10**9 else "\tLaminar Flow")

        # Set T_next for the next iteration
        alpha = water.alfa # (m^2/s) Thermal Diffusivity
        d = diameter # (m) diameter of cylinder
        Lc = d / 4 # Characteristic dimension of cylinder
        Fo = alpha * (t + 20) / Lc ** 2 # Fourier number
        Bi = h * Lc / k # Biot number
        T_next = math.exp(-Bi * Fo) * (T_initial - T_infinity) + T_infinity


# For Aluminium Specimen
print("Aluminium Specimen:")
compute(30.3, 63.9, 0.1, 0.025, 15)
# For Brass Specimen
print("\nBrass Specimen:")
compute(30.9, 63.6, 0.1, 0.025, 12)
