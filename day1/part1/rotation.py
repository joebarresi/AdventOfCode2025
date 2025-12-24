# Take in a file with a list of rotations
# solve for how many times it lands at 0

def file_as_rotations(file_path):
  try:
      directions = []
      with open(file_path, 'r') as file:
          for line in file:
            if line[0] == "L":
              directions.append(-1 * int(line[1:]))
            else:
              directions.append(int(line[1:]))
      return directions
  except FileNotFoundError:
      print(f"Error: The file '{file_path}' was not found.")
  except Exception as e:
      print(f"An error occurred: {e}")

def get_number_of_zeroes(rots):
  curSpot = 50
  num_zeroes = 0

  for i in range(0, len(rots)):
    # try to tell if it will pass
    curSpot += rots[i]

    if curSpot % 100 == 0:
      num_zeroes += 1

  return num_zeroes


def main():
  # do shit
  rots = file_as_rotations("rotos.md")

  print("Num Zeroes", get_number_of_zeroes(rots))



main()