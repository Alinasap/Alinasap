using System;

namespace Chess1_0
{
    class Program
    {
        private static bool IsKingCorrect(string start, string end)
        {
            int dx = Math.Abs(end[0] - start[0]);
            int dy = Math.Abs(end[1] - start[1]);
            return (dx == 1 && dy == 1) || (dx == 0 && dy == 1);
        }
       
        private static bool IsRookCorrect(string start, string end)
        {
            int dx = Math.Abs(end[0] - start[0]);
            int dy = Math.Abs(end[1] - start[1]);
            return (dx > 0 && dy == 0) || (dx == 0 && dy > 0);
        }
        
        private static bool IsBishopCorrect(string start, string end)
        {
            int dx = Math.Abs(end[0] - start[0]);
            int dy = Math.Abs(end[1] - start[1]);
            return (dx == dy) && (dx != 0) && (dy != 0);
        }
     
        private static bool IsQueenCorrect(string start, string end)
        {
           int dx = Math.Abs(end[0] - start[0]);
           int dy = Math.Abs(end[1] - start[1]);
           return (dx == dy) && (dx != 0) && (dy != 0) || (dx > 0 && dy == 0) || (dx == 0 && dy > 0);
        }
    
        private static bool IsKnightCorrect(string start, string end)
        {
            int dx = Math.Abs(end[0] - start[0]);
            int dy = Math.Abs(end[1] - start[1]);
            return dx + dy == 3 && dx * dy == 2;
        }

        private static bool IsPawnCorrect(string start, string end)
        {
            int dx = Math.Abs(end[0] - start[0]);
            int dy = Math.Abs(end[1] - start[1]);
            return (dx == 0 && dy == 1);
        }

        private static bool IsCorrectCoordinate(string coord)
        {
            char letter = coord[0];
            char num = coord[1];
            return coord.Length == 2 && letter >= 'A' && letter <= 'H' && num >= '1' && num <= '8';

        }

        private static string ReadCoord()
        {
            do
            {
                string input = Console.ReadLine().ToUpper();
                if (IsCorrectCoordinate(input))
                    return input;
                else
                    Console.WriteLine("Не корректная координата.");
            }

            while (true);
        }

        enum FigureType
        {
            King,
            Rook,
            Bishop,
            Queen,
            Knight,
            Pawn
        }

        private static FigureType ReadFigureType()
        {
            do
            {
                string input = Console.ReadLine();
                if (input == "0" || input.ToLower() == "king")
                    return FigureType.King;
                else if (input == "1" || input.ToLower() == "rook")
                    return FigureType.Rook;
                else if (input == "2" || input.ToLower() == "bishop")
                    return FigureType.Bishop;
                else if (input == "3" || input.ToLower() == "queen")
                    return FigureType.Queen;
                else if (input == "4" || input.ToLower() == "knight")
                    return FigureType.Knight;
                else if (input == "5" || input.ToLower() == "pawn")
                    return FigureType.Pawn;
                else
                    Console.WriteLine("Неверный тип фигуры.");
            }

            while (true);
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Добро пожаловать в игру <<Шахматы>>. Пожалуйста, выберите тип фигуры.");
            FigureType figure = ReadFigureType();
            Console.WriteLine("Введите начальную координату.");
            string start = ReadCoord();
            Console.WriteLine("Введите конечную координату.");
            string end = ReadCoord();
            bool IsCorrect = false;
            switch (figure)
            {
                case FigureType.King:
                    IsCorrect = IsKingCorrect(start, end);
                    break;
                case FigureType.Rook:
                    IsCorrect = IsRookCorrect(start, end);
                    break;
                case FigureType.Bishop:
                    IsCorrect = IsBishopCorrect(start, end);
                    break;
                case FigureType.Queen:
                    IsCorrect = IsQueenCorrect(start, end);
                    break;
                case FigureType.Knight:
                    IsCorrect = IsKnightCorrect(start, end);
                    break;
                case FigureType.Pawn:
                    IsCorrect = IsPawnCorrect(start, end);
                    break;
            }
            if (IsCorrect)
                Console.WriteLine("Фигура ходит правильно.");
            else
                Console.WriteLine("Фигура ходит не правильно.");
            Console.ReadKey();

        }
    }
}
