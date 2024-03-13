import java.util.HashMap;
import java.util.Map;
import java.lang.Math.*;

public class SenCosTanVisitorTest extends SenCosTanBaseVisitor<Double> {

    Map<String, Integer> memory = new HashMap<>();

    @Override
    public Double visitAssign(SenCosTanParser.AssignContext ctx) {
        String id = ctx.ID().getText();
        int value = visit(ctx.expr()).intValue();
        memory.put(id, value);
        return (double) value;
    }

    @Override
    public Double visitProg(SenCosTanParser.ProgContext ctx) {
        return super.visitProg(ctx);
    }

    @Override
    public Double visitPrint(SenCosTanParser.PrintContext ctx) {
        Double value = visit(ctx.expr());
        System.out.printf("%.3f\n", value); // Imprime con 2 decimales
        return 0.0; // Regresa 0.0 para mantener la consistencia
    }

    @Override
    public Double visitBlank(SenCosTanParser.BlankContext ctx) {
        return super.visitBlank(ctx);
    }

    @Override
    public Double visitId(SenCosTanParser.IdContext ctx) {
        String id = ctx.ID().getText();
        if (memory.containsKey(id)) {
            return (double) memory.get(id);
        }
        return 0.0;
    }

    @Override
    public Double visitInt(SenCosTanParser.IntContext ctx) {
        return Double.valueOf(ctx.INT().getText());
    }
        @Override
    public Double visitPi(SenCosTanParser.PiContext ctx) {
        return Math.PI;
    }
    
    @Override
    public Double visitFloat(SenCosTanParser.FloatContext ctx) {
        return Double.valueOf(ctx.FLOAT().getText());
   }

    @Override
    public Double visitAddSub(SenCosTanParser.AddSubContext ctx) {
        double left = visit(ctx.expr(0));
        double right = visit(ctx.expr(1));
        if (ctx.op.getType() == SenCosTanParser.ADD) {
            return left + right;
        }
        return left - right;
    }

    @Override
    public Double visitMulDiv(SenCosTanParser.MulDivContext ctx) {
        double left = visit(ctx.expr(0));
        double right = visit(ctx.expr(1));
        if (ctx.op.getType() == SenCosTanParser.MUL) {
            return left * right;
        }
        return left / right;
    }

    @Override
    public Double visitParens(SenCosTanParser.ParensContext ctx) {
        return visit(ctx.expr());
    }

    @Override
    public Double visitSin(SenCosTanParser.SinContext ctx) {
        double n = visit(ctx.expr());
        return Math.sin(n);
    }

    @Override
    public Double visitCos(SenCosTanParser.CosContext ctx) {
        double n = visit(ctx.expr());
        return Math.cos(n);
    }

    @Override
    public Double visitTan(SenCosTanParser.TanContext ctx) {
        double n = visit(ctx.expr());
        return Math.tan(n);
    }
}

