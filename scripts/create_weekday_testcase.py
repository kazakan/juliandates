from datetime import date, timedelta
import sys

def generate_date_lines(start_year, end_year, output_file):
    """
    Generates a file with each line formatted as "YYYY MM DD dayOfWeek" for the given range of years.

    Parameters:
        start_year (int): The starting year (inclusive).
        end_year (int): The ending year (inclusive).
        output_file (str): Path to the output file.
    """
    start_date = date(start_year, 1, 1)
    end_date = date(end_year, 12, 31)

    delta = timedelta(days=1)
    current_date = start_date

    lines = []
    while current_date <= end_date:
        formatted_line = current_date.strftime(f"%Y %m %d {current_date.isoweekday()}")
        lines.append(formatted_line)
        current_date += delta

    with open(output_file, 'w') as file:
        file.write(f"{len(lines)}\n")
        file.write("\n".join(lines) + '\n')

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <output_file>")
        sys.exit(1)

    output_file = sys.argv[1]
    generate_date_lines(2020, 2070, output_file)
