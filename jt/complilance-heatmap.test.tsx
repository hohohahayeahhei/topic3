import { render } from "@testing-library/react"
import '@testing-library/jest-dom/extend-expect'
import { ComplianceHeatmap } from "../compliance-heatmap"

describe("ComplianceHeatmap", () => {
  it("renders without crashing", () => {
    const { container } = render(<ComplianceHeatmap />)
    expect(container).toBeInTheDocument()
  })

  it("renders the correct number of data points", () => {
    const { container } = render(<ComplianceHeatmap />)
    const points = container.querySelectorAll(".recharts-scatter .recharts-scatter-symbol")
    expect(points).toHaveLength(15) // Assuming there are 15 data points in the chart
  })

  it("displays the correct data labels", () => {
    const { getByText } = render(<ComplianceHeatmap />)
    expect(getByText("Mon")).toBeInTheDocument()
    expect(getByText("Tue")).toBeInTheDocument()
    expect(getByText("Wed")).toBeInTheDocument()
    expect(getByText("Thu")).toBeInTheDocument()
    expect(getByText("Fri")).toBeInTheDocument()
    expect(getByText("Morning")).toBeInTheDocument()
    expect(getByText("Afternoon")).toBeInTheDocument()
    expect(getByText("Evening")).toBeInTheDocument()
  })
})