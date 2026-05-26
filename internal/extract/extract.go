package extract

import "aic8800d80/internal/pipeline"

type Result = pipeline.Result

func Run(root string, outDir string, minStringLen int, embeddingModel string, queueLimit int, queueMinScore float64, runTag string) (Result, error) {
	return pipeline.Run(root, outDir, minStringLen, embeddingModel, queueLimit, queueMinScore, runTag)
}
